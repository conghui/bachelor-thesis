/* ns: # of shots
 * nt: # of time steps
 * nz: # of elements in z dimension
 * ny: # of elements in y dimension
 * nx: # of elements in x dimension
 * stencil: stencil operator for one element*/
for (is = 0; is < ns; i++) 
  for (it = 1; it < nt - 1; it++) 
    for (iz = 0; iz < nz; iz++) 
      for (iy = 0; iy < ny; iy++) 
        for (ix = 0; ix < nx; ix++) {
          u[it+1][iz][iy][ix] = 2*u[it][iz][iy][ix] - u[it-1][iz][iy][ix] +
            dt*dt*(c*c*stencil(u[it][z][y][x]) + s[it]);
        }
