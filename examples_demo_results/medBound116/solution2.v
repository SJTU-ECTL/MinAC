module \solution-0 (
  x0, x1, x2, x3,
  out0, out1 );
  input x0, x1, x2, x3;
  output out0, out1;
  wire new_n5_, new_n6_;
  BUF_X1  g0(.A(x3),  .Z(out0));
  OR2_X1  g1(.A1(x1), .A2(x2), .ZN(out1));
  LOGIC0_X1  g1(.Z(new_n5_));
  LOGIC0_X1  g2(.Z(new_n6_));
endmodule
