module \solution-0 (
  x0, x1, x2, x3,
  out0, out1 );
  input x0, x1, x2, x3;
  output out0, out1;
  wire new_n4_;
  BUF_X1  g0(.A(x1),  .Z(out0));
  LOGIC0_X1  g0(.Z(new_n4_));
  OR2_X1  g2(.A1(x2), .A2(x3), .ZN(out1));
endmodule
