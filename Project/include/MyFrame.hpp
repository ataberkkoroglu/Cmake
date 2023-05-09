#ifndef _MYFRAMEH
  #include<wx/wx.h>
 
class MyFrame:public wxFrame{
    public:
      MyFrame (const wxString &title,const wxPoint &pos,const wxSize &size);
    private:
       void FileSaveAs(wxCommandEvent &WXUNUSED(event));
       wxDECLARE_EVENT_TABLE();
};


/*wxSplitterWindow::wxSplitterWindow	(	wxWindow * 	parent,
wxWindowID 	id = wxID_ANY,
const wxPoint & 	pos = wxDefaultPosition,
const wxSize & 	size = wxDefaultSize,
long 	style = wxSP_3D,
const wxString & 	name = "splitterWindow" 
)		*/


#define _MYFRAMEH

#endif