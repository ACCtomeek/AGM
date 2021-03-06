/*
 * Author: KoffeinFlummi
 *
 * Administers the unit epinephrine, waking it up.
 *
 * Argument:
 * 0: Unit to be treated (Object)
 *
 * Return value:
 * none
 */

#define EPINEPHRINETIME 7

// DETERMINE IF UNIT IS MEDIC
if !(([player] call AGM_Medical_fnc_isMedic) or {AGM_Medical_AllowNonMedics > 0}) exitWith {
  [localize "STR_AGM_Medical_NotTrained"] call AGM_Core_fnc_displayTextStructured;
};

_this spawn {
  _unit = _this select 0;

  _epinephrinetime = EPINEPHRINETIME;
  if !([player] call AGM_Medical_fnc_isMedic) then {
    _epinephrinetime = _epinephrinetime * AGM_Medical_CoefNonMedic;
  };

  player playMoveNow "AinvPknlMstpSnonWnonDnon_medic1"; // healing animation
  player setVariable ["AGM_CanTreat", false, false];

  if !([_unit, "AGM_Epipen"] call AGM_Medical_fnc_takeItem) exitWith {};

  AGM_Medical_epinephrineCallback = {
    _unit = _this select 0;

    player playMoveNow "AmovPknlMstpSrasWrflDnon";
    player setVariable ["AGM_CanTreat", true, false];

    if (player distance _unit > 4 or vehicle player != player or damage player >= 1 or (player getVariable "AGM_Unconscious")) exitWith {};

    [_unit] call AGM_Medical_fnc_wakeUp;

    if (profileNamespace getVariable ["AGM_keepMedicalMenuOpen", false]) then {
      [0, cursorTarget, "AGM_Medical"] call AGM_Interaction_fnc_showMenu;
    };
  };

  AGM_Medical_epinephrineAbort = {
    player playMoveNow "AmovPknlMstpSrasWrflDnon";
    player setVariable ["AGM_CanTreat", true, false];
  };

  [_epinephrinetime, _this, "AGM_Medical_epinephrineCallback", localize "STR_AGM_Medical_Injecting_Epinephrine", "AGM_Medical_epinephrineAbort"] call AGM_Core_fnc_progressBar;
  [_unit] call AGM_Core_fnc_closeDialogIfTargetMoves;
};
