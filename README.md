Lagcomp-Spoof
=============

This is a proof of concept hack for SA-MP clients, created so it can be fixed in future SA-MP versions. Players who install this mod, who's friends also install this mod can skin shoot each other on lagcomp disabled servers (and they will do double damage sometimes). The fix for this is for kye to add more sanity checks for lagcompmode on the server-side.

How to detect this hack in the mean time.
------------

```cpp
// OnPlayerWeaponShot will be called in lagcompmode OFF servers.
public OnPlayerWeaponShot(playerid, weaponid, hittype, hitid, Float:fX, Float:fY, Float:fZ)
{
  // it will be 0 in lagcompmode off servers
  // and 1 with lag comp mode on servers.
  // returning 0 always will prevent skin shoot in lagcompmode off servers.
  return GetServerVarAsInt("lagcompmode");
}
```
