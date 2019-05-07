using System;
using System.Collections.Generic;
using System.Text;
using System.IO;

namespace NET.MST.Third.CatchException
{
    class CatchException
    {
        static void Main(string[] args)
        {
            CatchException ce = new CatchException();
            ce.RiskWork();
            Console.Read();
        }
        public void RiskWork()
        {
            try
            {
                //一些預期可能產生例外的程式碼
            }
            //攔截NullReferenceException例外
            catch (NullReferenceException ex)
            {
                HandleExpectedException(ex);
            }
            //攔截ArgumentException例外
            catch (ArgumentException ex)
            {
                HandleExpectedException(ex);
            }
            //攔截FileNotFoundException例外
            catch (FileNotFoundException ex)
            {
                HandleError(ex);
            }
            //攔截所有衍生自Exception且先前未攔截到的例外
            catch (Exception ex)
            {
                HandleCrash(ex);
            }
        }
        //這裡處理預期可能會發生的，且不屬於錯誤範疇的例外
        private void HandleExpectedException(Exception ex)
        {
            Console.WriteLine(ex.ToString());
        }
        //這裡處理在系統出錯時，可能會發生比較嚴重的例外
        private void HandleError(Exception ex)
        {
            Console.WriteLine(ex.ToString());
            throw ex;   //嚴重的例外，拋到上層處理
        }
        private void HandleCrash(Exception ex)
        {
            Console.WriteLine(ex.ToString());
            System.Threading.Thread.CurrentThread.Abort();
        }
    }

}
