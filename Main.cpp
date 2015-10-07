//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include "GirlSelectClass.h"
#include "Main.h"
#include "GIFImage.hpp"

//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"

TForm1 *Form1;
GirlSelect Girl; 
//----------------------------------------------------------------------------
#include <io.h>

bool FileExists (const char *fname)
{
return access(fname,0) != -1;
}

//---------------------------------------------------------------------------
__fastcall TForm1::TForm1(TComponent* Owner)
   : TForm(Owner)
{
   String FileName;
   FileName = ExtractFilePath(Application->ExeName);
   FileName += "Amour.gif";
   TPicture::RegisterFileFormat(__classid(TGIFImage), "gif", "Files GIF", __classid(TGIFImage));
   if(FileExists(FileName))
   {
      Image1->Picture->LoadFromFile(FileName);
   }
   else
   {
      StringGrid1->Width += 285;
      StringGrid1->DefaultColWidth += 285;
   }
}
//---------------------------------------------------------------------------

void __fastcall TForm1::Button1Click(TObject *Sender)
{
   String TmpGirl;
   TmpGirl = Edit1->Text;
   Girl.AddGirl(TmpGirl);
   TmpGirl = Girl.ListGirl();
   String TmpTxt;
   int i=0;
   StringGrid1->RowCount = 1;
   while(true)
   {
      i++;
      TmpTxt += TmpGirl[i];

      if(TmpGirl[i] == '\t')
      {
         StringGrid1->Cells[0][StringGrid1->RowCount-1] = TmpTxt;
         StringGrid1->RowCount++;
         TmpTxt = "";
      }
      else if(TmpGirl[i] == '\n')
      {
         StringGrid1->RowCount--;
         break;
      }
   }
}
//---------------------------------------------------------------------------

void __fastcall TForm1::Button2Click(TObject *Sender)
{
   String TmpGirl;
   TmpGirl = Girl.SelectGirl();
   Edit2->Text = TmpGirl;

   TmpGirl = Girl.ListGirl();
   String TmpTxt;
   int i=0;
   StringGrid1->RowCount = 1;
   while(true)
   {
      i++;
      TmpTxt += TmpGirl[i];

      if(TmpGirl[i] == '\t')
      {
         StringGrid1->Cells[0][StringGrid1->RowCount-1] = TmpTxt;
         StringGrid1->RowCount++;
         TmpTxt = "";
      }
      else if(TmpGirl[i] == '\n')
      {
         StringGrid1->RowCount--;
         break;
      }
   }
}
//---------------------------------------------------------------------------

void __fastcall TForm1::Button3Click(TObject *Sender)
{
      Form1->Close();   
}
//---------------------------------------------------------------------------





