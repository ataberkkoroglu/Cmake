#include"include/MyFrame.hpp"
#include<wx/wx.h>
#include<wx/wfstream.h>
#include<wx/filedlg.h>
#include<wx/splitter.h>
#include <wx/panel.h>

wxBEGIN_EVENT_TABLE(MyFrame,wxFrame)
EVT_MENU(1,MyFrame::FileSaveAs)
wxEND_EVENT_TABLE()

enum {     //enum ad {} olarak da kullanılabilir.
   wxID_KAYDET,
   wxID_KAPAT
};
MyFrame::MyFrame(const wxString &title,const wxPoint &pos,const wxSize &size):wxFrame(NULL,wxID_ANY,title,pos,size){
   FreeConsole();
   wxMenu* menufile=new wxMenu;
   menufile->Append(wxID_KAYDET,"Kaydet",L"Bu Button Dosyayı Kaydeder.");
   menufile->AppendSeparator();
   menufile->Append(wxID_KAPAT,"Kapat",L"Bu Button Dosyayı Kapatır.");

   wxMenu* menu2=new wxMenu;
   menu2->Append(3,wxString::FromUTF8("Önemli Belgeler"),L"Yardım Açıklaması");
   wxMenuBar *menubar=new wxMenuBar;
   menubar->Append(menufile,"Dosya");
   menubar->Append(menu2,wxString::FromUTF8("Örnek"));

   CreateStatusBar();
   SetStatusText("Merhaba BTK");
   SetMenuBar(menubar);


wxSplitterWindow *splitter=new wxSplitterWindow(this,wxID_ANY,wxDefaultPosition,wxDefaultSize,wxSP_3DBORDER | wxSP_LIVE_UPDATE);
wxSplitterWindow *splitter2=new wxSplitterWindow(splitter,wxID_ANY,wxDefaultPosition,wxDefaultSize,wxSP_3DBORDER | wxSP_LIVE_UPDATE);
wxPanel *left=new wxPanel(splitter);
wxPanel *right=new wxPanel(splitter2);
wxPanel *bottom=new wxPanel(splitter2);
left->SetBackgroundColour(wxColour(255,0,0));
right->SetBackgroundColour(wxColour(0,0,255));
bottom->SetBackgroundColour(wxColour(0,255,0));

splitter2->SetMinimumPaneSize(100);
splitter->SetMinimumPaneSize(100);
splitter->SplitVertically(left,splitter2);
splitter2->SplitHorizontally(right,bottom);
}

void MyFrame::FileSaveAs(wxCommandEvent &WXUNUSED(event)){
    wxFileDialog 
        saveFileDialog(this, _(L"Dosyayı Txt Olarak Kaydet"),"", "",
                       L"TXT Dosyaları (*.txt)|*.txt", wxFD_SAVE|wxFD_OVERWRITE_PROMPT);
    if (saveFileDialog.ShowModal() == wxID_CANCEL)
       return;     // the user changed idea...
    
        
    wxFileOutputStream output_stream(saveFileDialog.GetPath());
    if (output_stream.wxStreamBase::IsOk()){
       wxFile file(saveFileDialog.GetPath(),wxFile::read_write);
       if (file.IsOpened()){
        file.Write(wxT("Merhaba Adbülbatın Yiğit Baş"));file.Close();
       }
    }
    else{
        wxLogError(L"Dosyanız Kaydedilemedi '%s'.", saveFileDialog.GetPath());
        return;
    }
}
