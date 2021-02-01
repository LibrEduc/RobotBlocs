// Interrupt service routines

void Rcount()  // increment right wheel counter when hall sensor detects change in magnetic field
{
  rcount++;
}


void Lcount()  // increment left wheel counter when hall sensor detects change in magnetic field
{
  lcount++;
}

