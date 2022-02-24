module \solution-0 (
  x0, x1, x2, x3,
  out0, out1 );
  input x0, x1, x2, x3;
  output out0, out1;
  wire new_n4_, new_n5_, new_n6_;
  OAI22_X1  g0(.A1(x0), .A2(x3), .B1(x1), .B2(x2), .ZN(new_n4_));
  NOR2_X1  g1(.A1(x2), .A2(x3), .ZN(new_n5_));
  NOR2_X1  g2(.A1(x0), .A2(x1), .ZN(new_n6_));
  OAI21_X1  g3(.A(new_n4_), .B1(new_n5_), .B2(new_n6_), .ZN(out1));  //carry
  AOI21_X1  g4(.A(out1), .B1(new_n5_), .B2(new_n6_), .ZN(out0));  //sum
endmodule
