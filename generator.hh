// generator.hh
#ifndef GENERATOR_HH
#define GENERATOR_HH

#include "G4VUserPrimaryGeneratorAction.hh"
#include "G4ParticleGun.hh"

class Generator : public G4VUserPrimaryGeneratorAction {
public:
    Generator();
    ~Generator();

    virtual void GeneratePrimaries(G4Event* anEvent);

private:
    G4ParticleGun* particleGun;
};

#endif // GENERATOR_HH
