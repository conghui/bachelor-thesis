/* ns: # of shots
 * nt: # of time steps
 * nz: # of elements in z dimension
 * ny: # of elements in y dimension
 * nx: # of elements in x dimension
 * s : source wave field array
 * r : receiver wave field array
 * res: the resulting image array, init as zeros
 * stencil: stencil operator for one element*/
for (is = 0; is < ns; i++)  {
  /* forward modeling */
  for (it = 2; it < nt ; it++) 
    for (iz = 0; iz < nz; iz++) 
      for (iy = 0; iy < ny; iy++) 
        for (ix = 0; ix < nx; ix++) {
          s(it,iz,iy,ix) = 2*s(it-1,iz,iy,ix) -
            s(it-2,iz,iy,ix) + dt*dt*c*c*stencil(s(it-1,z,y,x));

          if ((iz, iy, iz) corresponds to the source location)
            s(it,iz,iy,ix) += recored_source(it, iz, iy, ix);
          if ((iz, iy, ix) is in the boundary)
            process_boundary_condition();
        }

  /* reverse migration */
  for (it = nt - 1; it >= 2; it--) 
    for (iz = 0; iz < nz; iz++) 
      for (iy = 0; iy < ny; iy++) 
        for (ix = 0; ix < nx; ix++) {
          r(it-2,iz,iy,ix) = 2*r(it-1,iz,iy,ix) -
            r(it,iz,iy,ix) + dt*dt*c*c*stencil(s(it-1,z,y,x));

          if ((iz, iy, iz) corresponds to the source location)
            r(it-2,iz,iy,ix) += recored_source(it-2,iz,iy,ix);
          if ((iz, iy, ix) is in the boundary)
            process_boundary_condition();

          // correlate the source and receiver wave field 
          // into imaging results
          res(iz, iy, ix) += s(it-2,iz,iy,ix)*r(it-2,iz,iy,ix);
        }
}
