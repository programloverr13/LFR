// void tFree()
// {
//   blackAmount = 0;
//   isLeft = 0;
//   isRight = 0;
//   downL = 0;
//   downR = 0;
// }
// int isCenter()
// {
//   read();
//   calcBW();
//   return bwRead[6] + bwRead[7];
// }
// // int lineFoundCheck(int m, int n, int p) {
// //   read();
// //   calcBW();
// //   return bwRead[m] + bwRead[n] + bwRead[p];
// // }
// void calcBW()
// {
//   for (uint8_t i = 0; i < 14; i++)
//   {
//     if (i >= 3 && i <= 10)
//     {
//       blackAmount += bwRead[i];
//       if (i <= 5)
//         isLeft += bwRead[i];
//       else if (i >= 8)
//         isRight += bwRead[i];
//     }
//     else if (i < 3)
//       downL += bwRead[i];
//     else if (i > 10)
//       downR += bwRead[i];
//   }
// }
// void modeApply()
// {
//   switch (MODE)
//   {
//   case 0:
//     tL();
//     break;
//   case 1:
//     tR();
//     break;
//   default:
//     break;
//   }
// }
// int run()
// {
//   tFree();
//   calcBW();
// //  int resetI = 1;
//   // t-shape
//   // if (blackAmount < 2 && checkDownS() == 3)
//   // {
//   //   modeApply();
//   //   return 1;
//   // }
//   //stop
//     // else if (blackAmount >= 7 && downL > 0 && downR > 0) {
//     //   wheel(0, 0);
//     //   return 6;
//     // }
//   //  // plus shape
//   //  else if (blackAmount >= 6) {
//   //    if (FRONT == 0) {
//   //      modeApply();
//   //    }
//   //  }
//    if (blackAmount == 0)
//   {
//     switch (checkDownS())
//     {
//     case 1:
//       tL();
//       break;
//     case 2:
//       tR();
//       break;
//     case 3:
//       modeApply();
//       break;
//     case 0:
//       lost();
//       break;
//     }
//     return 3;
//   }
//   //
//   //  else if (isRight == 0 && isLeft >= 2 && checkDownS() == 1 && isCenter() > 0 &&
//   //           (MODE == 0 || LEFT_RIGHT == 1)) {
//   //    tL();
//   //    return 4;
//   //  } else if (isLeft == 0 && isRight >= 2 && checkDownS() == 2 &&
//   //             isCenter() > 0 && (MODE == 1 || LEFT_RIGHT == 1)) {
//   //    tR();
//   //    return 5;
//   //  }
//   else
//   {
//     fLine();
//     return 0;
//   }
//   //        resetI=0;
//   //    if(resetI!=0) I=0;
// }
// void fLine()
// {
//   if (downL > 0 && downR == 0)
//   {
//     lineOnLeft = 1;
//     lineOnRight = 0;
//   }
//   if (downR > 0 && downL == 0)
//   {
//     lineOnRight = 1;
//     lineOnLeft = 0;
//   }
//   calcError();
//   calcCorrect();
//   mkCorrect();
// }
// void tL()
// {
//     // aWheel(turnLow, turnHigh);
//     aWheel(0, turnHigh);
//     delay(backDelay);
//     while (isCenter() < 1)
//     {
//       aWheel(-turnLow, turnHigh);
//     }
// }
// void tR()
// {
//     aWheel(turnHigh, 0);
//     delay(backDelay);
//     while (isCenter() < 1)
//     {
//         aWheel(turnHigh, -turnLow);
//     }
//     // Serial.println("tr");
// }
// // void tL()
// // {
// //   while (isCenter() > 0)
// //   {
// //     aWheel(0, turnHigh);
// //   }
// //   // delay(backDelay);
// //   while (isCenter() != 0)
// //   {
// //     aWheel(-turnLow, turnHigh);
// //   }
// // }
// // void tR()
// // {
// //   while (isCenter() > 0)
// //   {
// //     aWheel(turnHigh, 0);
// //   }
// // //  wheel(0, 0);
// // //  delay(20);
// //   // delay(backDelay);
// //   while (isCenter() != 0)
// //   {
// //     aWheel(turnHigh, -turnLow);
// //   }
// // //  wheel(0, 0);
// // //  delay(20);
// // }

// int checkDownS()
// {
//   if (downL > 0 && downR == 0)
//     return 1;
//   else if (downR > 0 && downL == 0)
//     return 2;
//   else if (downL > 0 && downR > 0)
//     return 3;
//   else if (downL == 0 && downR == 0)
//     return 0;
// }
