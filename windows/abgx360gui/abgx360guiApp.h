//---------------------------------------------------------------------------
//
// Name:        abgx360guiApp.h
// Author:      Seacrest
// Created:     10/8/2007 9:06:46 PM
// Description: 
//
//---------------------------------------------------------------------------

#ifndef __ABGX360GUIApp_h__
#define __ABGX360GUIApp_h__

#ifdef __BORLANDC__
#pragma hdrstop
#endif

#ifndef WX_PRECOMP

#include <wx/wx.h>

#else
#include <wx/wxprec.h>
#endif

class abgx360guiApp : public wxApp {
public:
    bool OnInit();

    int OnExit();
};

#endif
