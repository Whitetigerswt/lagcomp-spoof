Lagcomp-Spoof
=============

The idea behind this mod was to allow OnPlayerWeaponShot and GetPlayerLastShotVectors to lagcomp disabled servers. 

- Only supports 0.3z client (not 0.3z-R2)

If you do not follow the instructions below exactly, players WILL be able to skin shoot each other if they are both using this mod. It's very important that server owners update their scripts with the following:


Adding support to this mod in your Lagcomp off server.
------------
```cpp
// OnPlayerWeaponShot will be called in lagcompmode OFF servers.
public OnPlayerWeaponShot(playerid, weaponid, hittype, hitid, Float:fX, Float:fY, Float:fZ)
{
  // it will be 0 in lagcompmode off servers
  // and 1 with lag comp mode on servers.
  // returning 0 always will prevent skin shoot in lagcompmode off servers.
  return GetServerVarAsInt("lagcompmode");
  // This will make skin shoot shots account to nothing.
}
```

Adding these lines of code is important. if you do not return 0 in OnPlayerWeaponShot in a lagcomp off servers, you leave open the potential for players to do double damage, and skin shoot each other.
