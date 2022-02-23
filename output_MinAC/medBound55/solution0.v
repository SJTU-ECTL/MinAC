module \solution-0 (
  x0, x1, x2, x3,
  out0, out1 );
  input x0, x1, x2, x3;
  output out0, out1;
  wire new_n4_;
  OR3_X1  g0(.A1(x0), .A2(x2), .A3(x3), .ZN(new_n4_));
  HA_X1  g1(.A(x1), .B(new_n4_), .CO(out1), .S(out0));
endmodule
