/* in:          3D input array
 * out:         3D output array
 * asserttion:  x, y, z are within [3, n-3), within the boundary
 * */
for (i = -3; i <= 3; i++) {
  out[z][y][x] += in[z][y][x+i];
  out[z][y][x] += in[z][y+i][x];
  out[z][y][x] += in[z+i][y][x];
  out -= 2*in[z][y][x];
}


