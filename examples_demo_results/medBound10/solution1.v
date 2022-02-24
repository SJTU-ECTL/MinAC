module \solution-0 (
  x0, x1, x2, x3,
  out0, out1 );
  input x0, x1, x2, x3;
  output out0, out1;
  wire new_n4_, new_n5_, new_n6_;
  AOI21_X1  g0(.A(x2), .B1(x1), .B2(x3), .ZN(new_n4_));
  OR2_X1  g1(.A1(x1), .A2(x3), .ZN(new_n5_));
  INV_X1  g2(.A(new_n4_), .ZN(new_n6_));
  FA_X1  g3(.A(x0), .B(new_n5_), .CI(new_n6_), .CO(out1), .S(out0));
endmodule
