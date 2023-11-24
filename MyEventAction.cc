// MyEventAction.cc
#include "MyEventAction.hh"
#include "G4Event.hh"

MyEventAction::MyEventAction() {}

MyEventAction::~MyEventAction() {}

void MyEventAction::BeginOfEventAction(const G4Event*) {
    // Add code to be executed at the beginning of each event
}

void MyEventAction::EndOfEventAction(const G4Event*) {
    // Add code to be executed at the end of each event
}
