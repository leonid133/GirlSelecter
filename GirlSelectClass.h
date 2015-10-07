//---------------------------------------------------------------------------

#ifndef GirlSelectClassH
#define GirlSelectClassH
#include <StdCtrls.hpp>
//---------------------------------------------------------------------------

class GirlSelect
{
   private:
      int countGirl;
      String *GirlData;
   public:
      GirlSelect():countGirl(1)
      {
         GirlData = new String[countGirl];
      }
      ~GirlSelect()
      {
         if(GirlData)delete[] GirlData;
      }
      String SelectGirl(void);
      void AddGirl(String _Girl);
      String ListGirl();
};
//---------------------------------------------------------------------------
#endif
