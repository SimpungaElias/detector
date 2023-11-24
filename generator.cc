#include "generator.hh"
#include "G4Event.hh"
#include "G4ParticleTable.hh"
#include "G4ParticleDefinition.hh"
#include "G4PrimaryVertex.hh"
#include "G4PrimaryParticle.hh"
#include "G4SystemOfUnits.hh"
#include "G4IonTable.hh"

Generator::Generator() {
    particleGun = new G4ParticleGun(1);

    // Set the particle type to Am-241
    G4ParticleTable* particleTable = G4ParticleTable::GetParticleTable();

    // Find the G4ParticleDefinition for Am-241
    G4ParticleDefinition* am241Definition = particleTable->FindParticle("americium241");

    // If Am-241 is not found, try to create a composite particle for Am-241
    if (!am241Definition) {
        G4int atomicNumber = 95; // Americium atomic number
        G4int atomicMass = 241;  // Americium atomic mass
        am241Definition = particleTable->GetIonTable()->GetIon(atomicNumber, atomicMass);
    }

    // Set the particle definition for the gun
    particleGun->SetParticleDefinition(am241Definition);

    // Set the particle energy and direction (you can customize these parameters)
    particleGun->SetParticleEnergy(14.0 * MeV);
    particleGun->SetParticleMomentumDirection(G4ThreeVector(0, 0, 1));
    
}

Generator::~Generator() {
    delete particleGun;
}

void Generator::GeneratePrimaries(G4Event* anEvent) {
    // Generate a primary vertex
    G4PrimaryVertex* vertex = new G4PrimaryVertex(G4ThreeVector(0, 0, -10.0), 0.0);

    // Generate a primary particle
    G4PrimaryParticle* particle = new G4PrimaryParticle(particleGun->GetParticleDefinition());
    particle->SetMomentumDirection(particleGun->GetParticleMomentumDirection());
    particle->SetKineticEnergy(particleGun->GetParticleEnergy());

    // Add the particle to the vertex
    vertex->SetPrimary(particle);

    // Add the vertex to the event
    anEvent->AddPrimaryVertex(vertex);
}

