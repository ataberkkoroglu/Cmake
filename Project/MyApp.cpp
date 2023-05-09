#include "include/MyApp.hpp"
#include "MyFrame.hpp"
#include<wx/wx.h>

bool MyApp::OnInit(){
    MyFrame *frame=new MyFrame("Merhaba wxWidgets",wxPoint(0,0),wxSize(500,500));
    frame->Show(true);
    return true;
}
wxIMPLEMENT_APP(MyApp);