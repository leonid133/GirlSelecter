//---------------------------------------------------------------------------


#pragma hdrstop

#include "GirlSelectClass.h"

//---------------------------------------------------------------------------
String GirlSelect::SelectGirl(void)
{
         String SelGirl("��� ���������");
         if(countGirl>1)
         {
            int Selected;
            randomize();
            Selected = 1 + rand() % (countGirl-1);
            SelGirl = GirlData[Selected];
            String *TmpGirlData = new String[countGirl];
            for(int i = 0; i< countGirl; i++)
            {
               TmpGirlData[i] = GirlData[i];
            }
            if(GirlData)delete[] GirlData;
            countGirl--;
            GirlData = new String[countGirl];
            for(int i = 0, i2 = 0; i< (countGirl+1); i++)
            {
               if(i != Selected)
               {
                  GirlData[i2] = TmpGirlData[i];
                  i2++;
               }
            }
         }
         return SelGirl;
}

void GirlSelect::AddGirl(String _Girl)
{
      if(_Girl > ""){
         String *TmpGirlData = new String[countGirl];
         for(int i = 0; i< countGirl; i++)
         {
            TmpGirlData[i] = GirlData[i];
         }
         if(GirlData)delete[] GirlData;
         countGirl++;
         GirlData = new String[countGirl];
         for(int i = 0; i< (countGirl-1); i++)
         {
            GirlData[i] = TmpGirlData[i];
         }
         GirlData[countGirl-1] = _Girl;
         if(TmpGirlData)delete [] TmpGirlData;
      }
}

String GirlSelect::ListGirl()
{
         String List;
         for(int i = 0; i < countGirl; i++)
         {
            if(i==0){List += "������ ...";}
            List += GirlData[i];
            List += "\t";
         }
         List += "\n";
         return List;
};
//---------------------------------------------------------------------------
#pragma package(smart_init)
