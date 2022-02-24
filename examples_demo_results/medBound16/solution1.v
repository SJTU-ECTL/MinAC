module \solution-0 (
  x0, x1, x2, x3,
  out0, out1 );
  input x0, x1, x2, x3;
  output out0, out1;
  wire new_n4_, new_n5_;
  NOR2_X1  g0(.A1(x0), .A2(x1), .ZN(new_n4_));
  INV_X1  g1(.A(new_n4_), .ZN(new_n5_));
  FA_X1  g2(.A(x2), .B(x3), .CI(new_n5_), .CO(out1), .S(out0));
endmodule
