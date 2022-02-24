module \solution-0 (
  x0, x1, x2, x3,
  out0, out1 );
  input x0, x1, x2, x3;
  output out0, out1;
  BUF_X1  g0(.A(x3),  .Z(out0));
  OR2_X1  g1(.A1(x0), .A2(x1), .ZN(out1));
endmodule
