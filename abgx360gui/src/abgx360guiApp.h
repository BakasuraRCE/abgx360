//---------------------------------------------------------------------------
//
// Name:        abgx360guiApp.h
// Author:      Seacrest
// Created:     10/8/2007 9:06:46 PM
// Description: 
//
//---------------------------------------------------------------------------

#pragma once

// PRECOMPILED_HEADERS
// https://docs.wxwidgets.org/3.0/page_multiplatform.html
// For compilers that support precompilation, includes "wx.h".
#include <wx/wxprec.h>

#ifdef __BORLANDC__
#   pragma hdrstop
#endif

#ifndef WX_PRECOMP
// Include your minimal set of headers here, or wx.h
#   include <wx/wx.h>
#endif
// PRECOMPILED_HEADERS

class abgx360guiApp : public wxApp {
 public:
  bool OnInit();
  int OnExit();
};