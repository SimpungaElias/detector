// MyDetectorConstruction.cc
#include "MyDetectorConstruction.hh"
#include "G4Box.hh"
#include "G4Tubs.hh"
#include "G4LogicalVolume.hh"
#include "G4PVPlacement.hh"
#include "G4NistManager.hh"
#include "G4Material.hh"
#include "G4VisAttributes.hh"

MyDetectorConstruction::MyDetectorConstruction() {
    // Initialize any member variables or perform setup here
}

MyDetectorConstruction::~MyDetectorConstruction() {
    // Perform cleanup if necessary
}

G4VPhysicalVolume* MyDetectorConstruction::Construct() {
    // Implement your geometry construction here
    // Define materials
    G4NistManager* nist = G4NistManager::Instance();
    G4Material* soilMaterial = nist->FindOrBuildMaterial("G4_Si");

    // Create logical volumes
    G4Box* soilBox = new G4Box("SoilBox", 10.0, 10.0, 10.0);
    G4LogicalVolume* soilLogical = new G4LogicalVolume(soilBox, soilMaterial, "SoilLogical");

    G4Tubs* cylinder = new G4Tubs("Cylinder", 0.0, 1.0, 20.0, 0.0, 360.0);
    G4LogicalVolume* cylinderLogical = new G4LogicalVolume(cylinder, soilMaterial, "CylinderLogical");

    // Place the cylinder at the bottom of the box
    new G4PVPlacement(0, G4ThreeVector(0, 0, -10.0), cylinderLogical, "CylinderPhysical", soilLogical, false, 0);

    // Set visualization attributes for the logical volumes
    G4VisAttributes* intersectionVis = new G4VisAttributes(G4Colour(0.8, 0.4, 0.8, 0.3));
    intersectionVis->SetForceSolid(true);
    cylinderLogical->SetVisAttributes(intersectionVis);  // Set attributes for the cylinder

    // Return the world physical volume
    G4VPhysicalVolume* worldPhysical = new G4PVPlacement(0, G4ThreeVector(), soilLogical, "World", 0, false, 0);
    return worldPhysical;
}
