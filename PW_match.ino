int matchPassword(String a, String b[] ) {

  for (int i = 0; i < numberOfUsers; i++)
  {
    if (a == b[i])
    {
      //    flag=true;
      return i ;
    }
  }
  return -1;
}
