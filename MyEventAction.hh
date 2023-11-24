// MyEventAction.hh
#ifndef MyEventAction_h
#define MyEventAction_h

#include "G4UserEventAction.hh"

class MyEventAction : public G4UserEventAction {
public:
    MyEventAction();
    virtual ~MyEventAction();

    virtual void BeginOfEventAction(const G4Event*);
    virtual void EndOfEventAction(const G4Event*);
};

#endif // MyEventAction_h
