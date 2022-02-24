//---------------------------------------------------------------------------
//
// Name:        abgx360guiApp.cpp
// Author:      Seacrest
// Created:     10/8/2007 9:06:46 PM
// Description: 
//
//---------------------------------------------------------------------------

#include "abgx360guiApp.h"
#include "abgx360gui.h"

IMPLEMENT_APP(abgx360guiApp)

bool abgx360guiApp::OnInit() {
    abgx360gui *frame = new abgx360gui(NULL);
    SetTopWindow(frame);
    frame->Show();
    return true;
}

int abgx360guiApp::OnExit() {
    return 0;
}
