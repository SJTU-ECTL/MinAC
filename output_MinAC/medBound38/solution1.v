module \solution-0 (
  x0, x1, x2, x3,
  out0, out1 );
  input x0, x1, x2, x3;
  output out0, out1;
  wire new_n4_, new_n5_;
  OR2_X1  g0(.A1(x0), .A2(x2), .ZN(new_n4_));
  OR2_X1  g1(.A1(x1), .A2(x3), .ZN(new_n5_));
  HA_X1  g2(.A(new_n4_), .B(new_n5_), .CO(out1), .S(out0));
endmodule
