module \solution-0 (
  x0, x1, x2, x3,
  out0, out1 );
  input x0, x1, x2, x3;
  output out0, out1;
  wire new_n5_;
  BUF_X1  g0(.A(x3),  .Z(out1));
  OR3_X1  g1(.A1(x0), .A2(x1), .A3(x2), .ZN(out0));
  LOGIC0_X1  g1(.Z(new_n5_));
endmodule
