// MyMainProgram.cc
#include "G4RunManager.hh"
#include "G4UImanager.hh"
#include "G4VisManager.hh"
#include "G4VisExecutive.hh"
#include "G4UIExecutive.hh"
#include "MyDetectorConstruction.hh"
#include "MyRunAction.hh"
#include "MyEventAction.hh"
#include "generator.hh"
#include "physics.hh" 

int main(int argc, char** argv) {
    // Create the Run Manager
    G4RunManager* runManager = new G4RunManager;

    // Set the custom physics list
    MyPhysicsList* physicsList = new MyPhysicsList;
    runManager->SetUserInitialization(physicsList);

    // Set mandatory initialization classes
    MyDetectorConstruction* detector = new MyDetectorConstruction;
    runManager->SetUserInitialization(detector);

    // Set user action classes
    runManager->SetUserAction(new MyRunAction);
    runManager->SetUserAction(new MyEventAction);

    // Set the custom generator as the primary generator action
    Generator* generator = new Generator();
    runManager->SetUserAction(generator);

    // Initialize G4 kernel
    runManager->Initialize();

    // Visualization setup
    G4UIExecutive *ui = new G4UIExecutive(argc, argv);
    G4VisManager *visManager = new G4VisExecutive();
    visManager->Initialize();
    G4UImanager *UImanager = G4UImanager::GetUIpointer();
    UImanager->ApplyCommand("/vis/open OGL");
    UImanager->ApplyCommand("/vis/viewer/set/viewpointVector 1 1 1");
    UImanager->ApplyCommand("/vis/drawVolume");
    UImanager->ApplyCommand("/vis/viewer/set/autoRefresh true");
    UImanager->ApplyCommand("/vis/scene/add/trajectories smooth");
    UImanager->ApplyCommand("/vis/scene/endOfEventAction accumulate");

    // Start the user interface
    ui->SessionStart();

    // Start a run
    runManager->BeamOn(10);

    // Terminate G4 kernel
    delete runManager;

    return 0;
}
