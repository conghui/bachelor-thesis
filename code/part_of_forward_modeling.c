for (iz = 0; iz < nz; iz++) 
  for (iy = 0; iy < ny; iy++) 
    for (ix = 0; ix < nx; ix++) {
      u[it+1][iz][iy][ix] = 2*u[it][iz][iy][ix] - u[it-1][iz][iy][ix] +
      dt*dt*(c*c*stencil(u[it][z][y][x]) + s[it]);

      if u[it+1][iz][iy][ix] is at boundary
        handle the boundary condition
    }

