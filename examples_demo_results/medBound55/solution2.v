module \solution-0 (
  x0, x1, x2, x3,
  out0, out1 );
  input x0, x1, x2, x3;
  output out0, out1;
  wire new_n4_, new_n5_;
  NOR2_X1  g0(.A1(x2), .A2(x3), .ZN(new_n4_));
  NOR2_X1  g1(.A1(x0), .A2(x1), .ZN(new_n5_));
  NOR2_X1  g2(.A1(new_n4_), .A2(new_n5_), .ZN(out1));
  NAND2_X1  g3(.A1(new_n4_), .A2(new_n5_), .ZN(out0));
endmodule
