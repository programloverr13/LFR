void CurveL() {
  wheel(turnLow, turnHigh);
  // delay(80);
  // wheel(-turnLow, turnHigh);
}
void CurveR() {
  wheel(turnHigh, turnLow);
  // delay(80);
  // wheel(-turnLow, turnHigh);
}
void downS(int n) {
  switch (n) {
    case 1:
      tL();
      break;
    case 2:
      tR();
      break;
    case 3:
      tL();
      break;
  }
}
void intersection() { tL(); }