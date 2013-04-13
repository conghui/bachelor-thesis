public class Stencil1D extends Kernel {
  public Stencil1D(KernelParameters parameters) {
    super(parameters);

    // Input Stream
    HWVar inStream = io.input("in_stream", hwFloat(8, 24));

    HWVar [] win = new HWVar[7];

    // accessing each element using stream offset
    for (int i = -3; i <= 3; i++) {
      win[i + 3] = stream.offset(inStream, i);
    }

    // stencil logic 
    HWVar result = (win[0] - win[6]) * (1.0/16) +
                   (win[1] - win[5]) * (1.0/8)  +
                   (win[2] - win[4]) * (1.0/4)  +
                   win[3] * (1.0/2);

    // Output
    io.output("out_stream", result, hwFloat(8, 24));
  }
}
