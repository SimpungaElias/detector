// MyDetectorConstruction.hh
#ifndef MyDetectorConstruction_h
#define MyDetectorConstruction_h

#include "G4VUserDetectorConstruction.hh"

class MyDetectorConstruction : public G4VUserDetectorConstruction {
public:
    MyDetectorConstruction();
    virtual ~MyDetectorConstruction();

    virtual G4VPhysicalVolume* Construct();
};

#endif // MyDetectorConstruction_h
