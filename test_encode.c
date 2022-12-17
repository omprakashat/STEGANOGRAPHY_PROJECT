/*************************************************************************************
Name  : Omprakash A Timashetti
Date : 15/11/2022
Description: Stegnography Project

************************************************************************************/




#include <stdio.h>
#include "encode.h"                                           //inclusion of encode.h file
#include "types.h"                                           //inclusion of enum
#include<string.h>
#include "common.h"                                         //common.h includes magic string
#include "decode.h"                                         //for Decode inclusion decode.h file

int main(int argc , char **argv)
{
    /*checking for operation */
  if( check_operation_type(argv) == e_encode)
  {
      printf("Selected encoding\n");
      EncodeInfo encInfo;
      /*Read and validate for Encoding */
      if ( read_and_validate_encode_args( argv,&encInfo) == e_success)
      {
          printf("Read and validate encode arguments is Success\n"); 
          if (do_encoding(&encInfo) == e_success)
          {
              printf("Encoding is Done successfully\n");
          }
          else
          {
              printf("Failed to encode\n");
              return e_failure;
          }
      }
      else
      {
          printf("Read and validate encode arguments is failure\n");
          return e_failure;
      }
  }
  else if (check_operation_type(argv) == e_decode)               //Check operation for decode part
  {
      printf("Selected Decoding\n");
     DecodeInfo decInfo;
     /*Read and validate for Decode part */
     if ( read_and_validate_decode_args( argv,&decInfo) == e_success)
      {
          printf("Read and validate encode arguments is Success\n"); 
          if (do_decoding(&decInfo) == e_success)
          {
              printf("Decoding is Done successfully\n");
          }
          else
          {
              printf("Failed to decode\n");
              return e_failure;
          }
      }
      else
      {
          printf("Read and validate encode arguments is failure\n");
          return e_failure;
      }

  }
  else
  {
      printf("Invalid option!!\nusage for encoding : \n ./a.out -e beautiful.bmp secrete.txt [stego.bmp] \nUsage for Decoding : \n ./a.out  -d stego.bmp [decode.txt]\n ");
  }
    return 0;
}

/* Check opeartion Type  Function  */
 OperationType check_operation_type(char *argv[])
{
    if(strcmp(argv[1],"-e") == 0)
    {
        return e_encode;
    }
    else if (strcmp(argv[1],"-d") == 0)
    {
      return e_decode;
    }
    else
    {
        return e_unsupported;
    }
}






