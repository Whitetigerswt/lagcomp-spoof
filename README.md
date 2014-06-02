Lagcomp-Spoof
=============

This is a proof of concept hack for SA-MP clients, created so it can be fixed in future SA-MP versions. Players who install this mod, who's friends also install this mod can skin shoot each other on lagcomp disabled servers. The fix for this is for kye to add more sanity checks for lagcompmode on the server-side.

How to detect this hack in the mean time.
------------

```cpp
public OnPlayerWeaponShot(playerid, weaponid, hittype, hitid, Float:fX, Float:fY, Float:fZ)
{
  new lagcomp = GetServerVarAsInt("lagcompmode");
  if(lagcomp == 0) return 0;
}
```
