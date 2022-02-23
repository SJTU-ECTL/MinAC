module \solution-0 (
  x0, x1, x2, x3,
  out0, out1 );
  input x0, x1, x2, x3;
  output out0, out1;
  wire new_n5_;
  OR4_X1  g0(.A1(x0), .A2(x1), .A3(x2), .A4(x3), .ZN(out0));
  AOI22_X1  g1(.A1(x0), .A2(x1), .B1(x2), .B2(x3), .ZN(new_n5_));
  INV_X1  g2(.A(new_n5_), .ZN(out1));
endmodule
