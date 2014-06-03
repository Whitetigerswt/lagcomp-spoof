Lagcomp-Spoof
=============

The original idea behind this mod was to allow OnPlayerWeaponShot and GetPlayerLastShotVectors to lagcomp disabled servers, however, this use had to be trashed when it was realized that when 2 or more players install this mod on the same lag comp disabled servers, they can damage each other based on skin shoot(and sometimes do double damage). So now, this is serving as a proof of concept hack for SA-MP clients, still online so it can be fixed in future SA-MP versions. The fix for this is for kye to add more sanity checks for lagcompmode on the server-side.

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
  // This will make the hack useless.
}
```
