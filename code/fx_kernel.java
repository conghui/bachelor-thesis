public class SimpleKernel extends Kernel {
  public SimpleKernel(KernelParameters parameters) {
    super(parameters);

    // Input Stream, "x" is the id of the stream
    HWVar x = io.input("x", hwFloat(8, 24));

    // The filter of the kernel
    HWVar y = 2 * x + 3;

    // Output stream, denoted by "y"
    io.output("y", y, hwFloat(8, 24));
  }
}
