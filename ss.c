module tanjim_exp_4_mealy(clk, reset, w, z, y, Y);
        
        input clk, reset, w;
        output reg z;
        output reg [1:0]y, Y;

        parameter [1:0] A = 2'b00, B = 2'b01, C = 2'b10;

        always @(posedge clk, posedge reset)
        begin
                if (reset == 1)
                begin
                      y = 0;
                      Y = 0;
                      z = 0;
                end
                else
                begin
                      y = Y;

                      case(y)
                          
                          A: if(w)
                                  begin
                                  z = 0;
                                  Y = B;
                                  end
                              else 
                                  begin
                                  z = 0;
                                  Y = A;
                                  end
                          
                          B: if(w)
                                  begin
                                  z = 0;
                                  Y = C;
                                  end
                              else 
                                  begin
                                  z = 0;
                                  Y = A;
                                  end
                          
                          
                          C: if(w)
                                  begin
                                  z = 1;
                                  Y = C;
                                  end
                              else 
                                  begin
                                  z = 0;
                                  Y = A;
                                  end
                          default: Y = 2'bxx;
                          
                      endcase
                end
        end
endmodule