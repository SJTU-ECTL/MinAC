module \solution-0 (
  x0, x1, x2, x3,
  out0, out1 );
  input x0, x1, x2, x3;
  output out0, out1;
  wire new_n40_, new_n41_, new_n50_;
  FA_X1  g0(.A(x0), .B(x1), .CI(x2), .CO(new_n40_), .S(new_n41_));
  HA_X1  g1(.A(x3), .B(new_n41_), .CO(new_n50_), .S(out0));
  OR2_X1  g2(.A1(new_n40_), .A2(new_n50_), .ZN(out1));
endmodule
