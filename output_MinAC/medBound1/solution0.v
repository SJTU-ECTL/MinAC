module \solution-0 (
  x0, x1, x2, x3,
  out0, out1 );
  input x0, x1, x2, x3;
  output out0, out1;
  wire new_n40_, new_n41_, new_n5_, new_n60_;
  FA_X1  g0(.A(x0), .B(x2), .CI(x3), .CO(new_n40_), .S(new_n41_));
  AND3_X1  g1(.A1(x1), .A2(new_n40_), .A3(new_n41_), .ZN(new_n5_));
  FA_X1  g2(.A(x1), .B(new_n41_), .CI(new_n5_), .CO(new_n60_), .S(out0));
  OR2_X1  g3(.A1(new_n40_), .A2(new_n60_), .ZN(out1));
endmodule
