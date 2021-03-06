class CfgPatches {
  class AGM_Interaction {
    units[] = {};
    weapons[] = {"AGM_CableTie"};
    requiredVersion = 0.60;
    requiredAddons[] = {AGM_Core};
    version = "0.94.1";
    versionStr = "0.94.1";
    versionAr[] = {0,94,1};
    author[] = {"commy2", "KoffeinFlummi", "CAA-Picard"};
    authorUrl = "https://github.com/commy2/";
  };
};

class CfgFunctions {
  class AGM_Interaction {
    class AGM_Interaction {
      file = "\AGM_interaction\functions";
      class addInteraction;
      class addInteractionSelf;
      class AddSelectableItem;
      class addToTooltip;
      class applyButtons;
      class canInteractWith;
      class canLockDoor;
      class canTapShoulder;
      class getActions2;
      class GetActions;      
      class getDoor;
      class getDown;
      class getSelectedButton;
      class hideMenu;
      class hideMouseHint;
      class initialiseInteraction;
      class isInRange;
      class joinTeam;
      class lockDoor;
      class menuKeyInput;
      class moveDown;
      class onButtonDown;
      class onButtonDownSelf;
      class onButtonUp;
      class onClick;
      class openDoor;
      class openMenu;
      class openMenuSelf;
      class openSelectMenu;
      class openSubMenu;
      class openSubMenuSelf;
      class prepareSelectMenu;
      class push;
      class removeInteraction;
      class removeInteractionSelf;
      class removeTag;
      class sendAway;
      class showMenu;
      class showMouseHint;
      class sortOptionsByPriority;
      class tapShoulder;
      class updateTooltipPosition;

      // backwards compatibility, remove in some patches
      class getCaptivityStatus;
      class setCaptivityStatus;
    };
  };
};

class Extended_PostInit_EventHandlers {
  class AGM_Interaction {
    clientInit = "call compile preprocessFileLineNumbers '\AGM_Interaction\clientInit.sqf'";
  };
};

class AGM_Core_Default_Keys {
  class openInteractionMenuNew {
    displayName = "$STR_AGM_Interaction_InteractionMenu";
    condition = "alive player";
    statement = "call AGM_Interaction_fnc_onButtonDown";
    conditionUp = "!isNull (findDisplay 1713999) && {profileNamespace getVariable ['AGM_Interaction_AutoCloseMenu', false]}";
    statementUp = "if (AGM_Interaction_MenuType mod 2 == 0) then {call AGM_Interaction_fnc_onButtonUp};";
    exceptions[] = {"AGM_Drag_isNotDragging", "AGM_Medical_canTreat", "AGM_Interaction_isNotEscorting"};
    key = 219;
    shift = 0;
    control = 0;
    alt = 0;
  };
  class openInteractionMenuSelfNew {
    displayName = "$STR_AGM_Interaction_InteractionMenuSelf";
    condition = "alive player";
    statement = "call AGM_Interaction_fnc_onButtonDownSelf";
    conditionUp = "!isNull (findDisplay 1713999) && {profileNamespace getVariable ['AGM_Interaction_AutoCloseMenu', false]}";
    statementUp = "if (AGM_Interaction_MenuType mod 2 == 1) then {call AGM_Interaction_fnc_onButtonUp};";
    exceptions[] = {"AGM_Drag_isNotDragging", "AGM_Medical_canTreat", "AGM_Interaction_isNotEscorting", "AGM_Core_notOnMap"};
    key = 219;
    shift = 0;
    control = 1;
    alt = 0;
  };
  class openDoor {
    displayName = "$STR_AGM_Interaction_OpenDoor";
    condition = "!AGM_Interaction_isOpeningDoor";
    statement = "call AGM_Interaction_fnc_openDoor";
    conditionUp = "AGM_Interaction_isOpeningDoor";
    statementUp = "AGM_Interaction_isOpeningDoor = false";
    key = 57;
    shift = 0;
    control = 1;
    alt = 0;
  };
  // disabled for now
  /*class lockDoor {
    displayName = "$STR_AGM_Interaction_LockDoor";
    condition = "[true] call AGM_Interaction_fnc_canLockDoor && {!AGM_Interaction_isOpeningDoor}";
    statement = "[true] call AGM_Interaction_fnc_lockDoor";
    key = 57;
    shift = 0;
    control = 0;
    alt = 1;
  };
  class unlockDoor {
    displayName = "$STR_AGM_Interaction_UnlockDoor";
    condition = "[false] call AGM_Interaction_fnc_canLockDoor";
    statement = "[false] call AGM_Interaction_fnc_lockDoor";
    key = 57;
    shift = 0;
    control = 1;
    alt = 1;
  };*/
  class tapShoulder {
    displayName = "$STR_AGM_Interaction_TapShoulder";
    condition = "[player, cursorTarget] call AGM_Interaction_fnc_canTapShoulder";
    statement = "[player, cursorTarget] call AGM_Interaction_fnc_tapShoulder";
    key = 20;
    shift = 1;
    control = 0;
    alt = 0;
  };
  class modifierKey {
    displayName = "$STR_AGM_Interaction_ModifierKey";
    condition = "";
    statement = "AGM_Modifier = 1;";
    conditionUp = "";
    statementUp = "AGM_Modifier = 0;";
    exceptions[] = {"AGM_Drag_isNotDragging"};
    key = 29;
    shift = 0;
    control = 0;
    alt = 0;
  };
};

class AGM_Core_Options {
  class Interaction_FlowMenu {
    displayName = "$STR_AGM_Interaction_FlowMenu";
    default = 0;
  };
  class Interaction_AutoCloseMenu {
    displayName = "$STR_AGM_Interaction_AutoCloseMenu";
    default = 0;
  };
  class Interaction_AutoCenterCursor {
    displayName = "$STR_AGM_Interaction_AutoCenterCursor";
    default = 1;
  };
};

class AGM_Parameters {
  AGM_Modifier = 0;
};

class AGM_Core_canInteractConditions {
  class AGM_Interaction_isNotEscorting {
    condition = "!(_player getVariable ['AGM_isEscorting', false])";
  };
  class AGM_Interaction_isNotCaptive {
    condition = "!(_player getVariable ['AGM_isCaptive', false])";
  };
  class AGM_Interaction_isNotSurrendering {
    condition = "!(_player getVariable ['AGM_isSurrender', false])";
  };
  class AGM_Interaction_isNotSwimming {
    condition = "!underwater _player";
  };
};

class CfgMovesBasic;
class CfgMovesMaleSdr: CfgMovesBasic {
  /*class Actions {     // This is ReadOnlyVerified
    class RifleStandSaluteActions;
    class AGM_RifleStandSaluteActions: RifleStandSaluteActions {
      getOver = "";
    };
  };*/
  class States {
    class CutSceneAnimationBase;
    class AmovPercMstpSnonWnonDnon_EaseIn: CutSceneAnimationBase {
      //actions = "AGM_RifleStandSaluteActions";
      head = "headDefault";
      static = 1;
      disableWeapons = 0;
      forceAim = 0;
      InterpolateTo[] = {"AmovPercMstpSnonWnonDnon_EaseOut",0.02,"Unconscious",0.1};
    };
    class AmovPercMstpSnonWnonDnon_Ease: AmovPercMstpSnonWnonDnon_EaseIn {
      looped = 0;
      InterpolateTo[] = {"Unconscious",0.1};
    };
    class AmovPercMstpSnonWnonDnon_EaseOut: AmovPercMstpSnonWnonDnon_EaseIn {
      InterpolateTo[] = {"AmovPercMstpSnonWnonDnon_EaseIn",0.02,"Unconscious",0.1};
    };
  };
};

#define MACRO_ADDITEM(ITEM,COUNT) class _xx_##ITEM { \
  name = #ITEM; \
  count = COUNT; \
};

class CfgVehicles {
  class Man;
  class CAManBase: Man {
    class AGM_Actions {
      class AGM_TeamManagement {
        displayName = "$STR_AGM_Interaction_TeamManagement";
        distance = 4;
        condition = "alive (_this select 0) && {!isPlayer (_this select 0)} && {(_this select 0) in units group (_this select 1)}";
        statement = "";
        showDisabled = 0;
        priority = 3.2;
        icon = "\AGM_Interaction\UI\team\team_management_ca.paa";
        subMenu[] = {"AGM_TeamManagement", 0};
        hotkey = "M";

        class AGM_JoinTeamRed {
          displayName = "$STR_AGM_Interaction_JoinTeamRed";
          distance = 4;
          condition = "alive (_this select 0) && {!isPlayer (_this select 0)} && {(_this select 0) in units group (_this select 1)}";
          statement = "[_this select 0, 'RED'] call AGM_Interaction_fnc_joinTeam";
          showDisabled = 1;
          icon = "\AGM_Interaction\UI\team\team_red_ca.paa";
          priority = 2.4;
          hotkey = "R";
        };
        class AGM_JoinTeamGreen {
          displayName = "$STR_AGM_Interaction_JoinTeamGreen";
          distance = 4;
          condition = "alive (_this select 0) && {!isPlayer (_this select 0)} && {(_this select 0) in units group (_this select 1)}";
          statement = "[_this select 0, 'GREEN'] call AGM_Interaction_fnc_joinTeam";
          showDisabled = 1;
          icon = "\AGM_Interaction\UI\team\team_green_ca.paa";
          priority = 2.3;
          hotkey = "G";
        };
        class AGM_JoinTeamBlue {
          displayName = "$STR_AGM_Interaction_JoinTeamBlue";
          distance = 4;
          condition = "alive (_this select 0) && {!isPlayer (_this select 0)} && {(_this select 0) in units group (_this select 1)}";
          statement = "[_this select 0, 'BLUE'] call AGM_Interaction_fnc_joinTeam";
          showDisabled = 1;
          icon = "\AGM_Interaction\UI\team\team_blue_ca.paa";
          priority = 2.2;
          hotkey = "B";
        };
        class AGM_JoinTeamYellow {
          displayName = "$STR_AGM_Interaction_JoinTeamYellow";
          distance = 4;
          condition = "alive (_this select 0) && {!isPlayer (_this select 0)} && {(_this select 0) in units group (_this select 1)}";
          statement = "[_this select 0, 'YELLOW'] call AGM_Interaction_fnc_joinTeam";
          showDisabled = 1;
          icon = "\AGM_Interaction\UI\team\team_yellow_ca.paa";
          priority = 2.1;
          hotkey = "Y";
        };

        class AGM_LeaveTeam {
          displayName = "$STR_AGM_Interaction_LeaveTeam";
          distance = 4;
          condition = "alive AGM_Interaction_Target && {!isPlayer AGM_Interaction_Target} && {AGM_Interaction_Target in units group player} && {assignedTeam player != 'MAIN'}";
          statement = "[AGM_Interaction_Target, 'MAIN'] call AGM_Interaction_fnc_joinTeam";
          showDisabled = 1;
          icon = "\AGM_Interaction\UI\team\team_white_ca.paa";
          priority = 2.5;
          hotkey = "N";
        };
      };

      class AGM_TapShoulder {
        displayName = "$STR_AGM_Interaction_TapShoulder";
        distance = 4;
        condition = "[player, AGM_Interaction_Target] call AGM_Interaction_fnc_canTapShoulder";
        statement = "[player, AGM_Interaction_Target] call AGM_Interaction_fnc_tapShoulder";
        showDisabled = 1;
        priority = 2.8;
        hotkey = "Q";
      };
      class AGM_JoinGroup {
        displayName = "$STR_AGM_Interaction_JoinGroup";
        distance = 4;
        condition = "playerSide == side AGM_Interaction_Target && {group player != group AGM_Interaction_Target}";
        statement = "[player] joinSilent group AGM_Interaction_Target;";
        showDisabled = 0;
        priority = 2.6;
        icon = "\AGM_Interaction\UI\team\team_management_ca.paa";
        hotkey = "J";
      };

      class AGM_GetDown {
        displayName = "$STR_AGM_Interaction_GetDown";
        distance = 4;
        condition = "[AGM_Interaction_Target] call AGM_Interaction_fnc_canInteractWith";
        statement = "[AGM_Interaction_Target] call AGM_Interaction_fnc_getDown";
        showDisabled = 0;
        priority = 2.2;
      };
      class AGM_SendAway {
        displayName = "$STR_AGM_Interaction_SendAway";
        distance = 4;
        condition = "[AGM_Interaction_Target] call AGM_Interaction_fnc_canInteractWith";
        statement = "[AGM_Interaction_Target] call AGM_Interaction_fnc_sendAway";
        showDisabled = 0;
        priority = 2.0;
      };
      class AGM_Pardon {
        displayName = "$STR_AGM_Interaction_Pardon";
        distance = 4;
        condition = "rating AGM_Interaction_Target < -2000 && {alive AGM_Interaction_Target} && {playerSide == side group AGM_Interaction_Target}";
        statement = "[AGM_Interaction_Target, '{_this addRating -rating _this}', AGM_Interaction_Target] call AGM_Core_fnc_execRemoteFnc";
        showDisabled = 0;
        priority = 2.5;
      };
    };

    class AGM_SelfActions {
      class AGM_TeamManagement {
        displayName = "$STR_AGM_Interaction_TeamManagement";
        condition = "true";
        statement = "";
        showDisabled = 1;
        priority = 3.2;
        icon = "\AGM_Interaction\UI\team\team_management_ca.paa";
        subMenu[] = {"AGM_TeamManagement", 1};
        enableInside = 1;
        hotkey = "M";

        class AGM_JoinTeamRed {
          displayName = "$STR_AGM_Interaction_JoinTeamRed";
          condition = "true";
          statement = "[player, 'RED'] call AGM_Interaction_fnc_joinTeam";
          showDisabled = 1;
          priority = 2.4;
          icon = "\AGM_Interaction\UI\team\team_red_ca.paa";
          enableInside = 1;
          hotkey = "R";
        };
        class AGM_JoinTeamGreen {
          displayName = "$STR_AGM_Interaction_JoinTeamGreen";
          condition = "true";
          statement = "[player, 'GREEN'] call AGM_Interaction_fnc_joinTeam";
          showDisabled = 1;
          priority = 2.3;
          icon = "\AGM_Interaction\UI\team\team_green_ca.paa";
          enableInside = 1;
          hotkey = "G";
        };
        class AGM_JoinTeamBlue {
          displayName = "$STR_AGM_Interaction_JoinTeamBlue";
          condition = "true";
          statement = "[player, 'BLUE'] call AGM_Interaction_fnc_joinTeam";
          showDisabled = 1;
          priority = 2.2;
          icon = "\AGM_Interaction\UI\team\team_blue_ca.paa";
          enableInside = 1;
          hotkey = "B";
        };
        class AGM_JoinTeamYellow {
          displayName = "$STR_AGM_Interaction_JoinTeamYellow";
          condition = "true";
          statement = "[player, 'YELLOW'] call AGM_Interaction_fnc_joinTeam";
          showDisabled = 1;
          priority = 2.1;
          icon = "\AGM_Interaction\UI\team\team_yellow_ca.paa";
          enableInside = 1;
          hotkey = "Y";
        };

        class AGM_LeaveTeam {
          displayName = "$STR_AGM_Interaction_LeaveTeam";
          condition = "assignedTeam player != 'MAIN'";
          statement = "[player, 'MAIN'] call AGM_Interaction_fnc_joinTeam";
          showDisabled = 1;
          priority = 2.5;
          icon = "\AGM_Interaction\UI\team\team_white_ca.paa";
          enableInside = 1;
          hotkey = "N";
        };

        class AGM_BecomeLeader {
          displayName = "$STR_AGM_Interaction_BecomeLeader";
          condition = "count (units group player) > 1 && {leader group player != player}";
          statement = "_newGroup = createGroup side player; (units group player) joinSilent _newGroup; _newGroup selectLeader player;";
          showDisabled = 1;
          priority = 1.0;
          icon = "\AGM_Interaction\UI\team\team_white_ca.paa";
          enableInside = 1;
          hotkey = "L";
        };
        class AGM_LeaveGroup {
          displayName = "$STR_AGM_Interaction_LeaveGroup";
          condition = "count (units group player) > 1";
          statement = "_oldGroup = units group player; _newGroup = createGroup side player; [player] joinSilent _newGroup; {player reveal _x} forEach _oldGroup;";
          showDisabled = 1;
          priority = 1.2;
          icon = "\AGM_Interaction\UI\team\team_management_ca.paa";
          enableInside = 1;
          hotkey = "M";
        };
      };

      /* DANCE ANIMATION DOESN'T WORK :(
      class AGM_Dance {
        displayName = "$STR_AGM_Interaction_Dance";
        condition = "isClass (configFile >> 'CfgPatches' >> 'AGM_Movement') and !AGM_Dancing";
        statement = "AGM_Dancing = true; [-2, {_this switchMove 'TestDance';}, player] call CBA_fnc_globalExecute;";
        showDisabled = 0;
        priority = -1.2;
      };
      class AGM_StopDancing {
        displayName = "$STR_AGM_Interaction_StopDancing";
        condition = "AGM_Dancing";
        statement = "AGM_Dancing = false; [-2, {_this switchMove '';}, player] call CBA_fnc_globalExecute;";
        showDisabled = 0;
        priority = -1.2;
      };
      */

      class AGM_Gestures {
        displayName = "$STR_AGM_Interaction_Gestures";
        condition = "canStand (_this select 0)";
        statement = "";
        showDisabled = 1;
        priority = 3.5;
        subMenu[] = {"AGM_Gestures", 1};
        icon = "AGM_Interaction\UI\gestures_ca.paa";
        hotkey = "G";

        /*class AGM_Gesture_Advance {
          displayName = "$STR_AGM_Interaction_Gestures_Attack";
          condition = "canStand (_this select 0)";
          statement = "(_this select 0) playActionNow 'gestureAttack';";
          showDisabled = 1;
          priority = 2.0;
        };*/
        class AGM_Gesture_Advance {
          displayName = "$STR_AGM_Interaction_Gestures_Advance";
          condition = "canStand (_this select 0)";
          statement = "(_this select 0) playActionNow 'gestureAdvance';";
          showDisabled = 1;
          priority = 1.9;
          hotkey = "1";
        };
        class AGM_Gesture_Go {
          displayName = "$STR_AGM_Interaction_Gestures_Go";
          condition = "canStand (_this select 0)";
          statement = "(_this select 0) playActionNow (['gestureGo', 'gestureGoB'] select (floor random 2));";
          showDisabled = 1;
          priority = 1.8;
          hotkey = "2";
        };
        class AGM_Gesture_Follow {
          displayName = "$STR_AGM_Interaction_Gestures_Follow";
          condition = "canStand (_this select 0)";
          statement = "(_this select 0) playActionNow 'gestureFollow';";
          showDisabled = 1;
          priority = 1.7;
          hotkey = "3";
        };
        /*class AGM_Gesture_Point {
          displayName = "$STR_AGM_Interaction_Gestures_Point";
          condition = "canStand (_this select 0)";
          statement = "(_this select 0) playActionNow 'gesturePoint';";
          showDisabled = 1;
          priority = 1.6;
        };*/
        class AGM_Gesture_Up {
          displayName = "$STR_AGM_Interaction_Gestures_Up";
          condition = "canStand (_this select 0)";
          statement = "(_this select 0) playActionNow 'gestureUp';";
          showDisabled = 1;
          priority = 1.5;
          hotkey = "4";
        };
        class AGM_Gesture_Cover {
          displayName = "$STR_AGM_Interaction_Gestures_Cover";
          condition = "canStand (_this select 0)";
          statement = "(_this select 0) playActionNow 'gestureCover';";
          showDisabled = 1;
          priority = 1.4;
          hotkey = "5";
        };
        class AGM_Gesture_CeaseFire {
          displayName = "$STR_AGM_Interaction_Gestures_Cease_Fire";
          condition = "canStand (_this select 0)";
          statement = "(_this select 0) playActionNow 'gestureCeaseFire';";
          showDisabled = 1;
          priority = 1.3;
          hotkey = "6";
        };
        class AGM_Gesture_Freeze {
          displayName = "$STR_AGM_Interaction_Gestures_Freeze";
          condition = "canStand (_this select 0)";
          statement = "(_this select 0) playActionNow 'gestureFreeze';";
          showDisabled = 1;
          priority = 1.2;
          hotkey = "7";
        };
        class AGM_Gesture_Yes {
          displayName = "$STR_AGM_Interaction_Gestures_Yes";
          condition = "canStand (_this select 0)";
          statement = "(_this select 0) playActionNow (['gestureYes', 'gestureNod'] select (floor random 2));";
          showDisabled = 1;
          priority = 1.1;
          hotkey = "8";
        };
        class AGM_Gesture_No {
          displayName = "$STR_AGM_Interaction_Gestures_No";
          condition = "canStand (_this select 0)";
          statement = "(_this select 0) playActionNow 'gestureNo';";
          showDisabled = 1;
          priority = 1.0;
          hotkey = "9";
        };
        class AGM_Gesture_Hi {
          displayName = "$STR_AGM_Interaction_Gestures_Hi";
          condition = "canStand (_this select 0)";
          statement = "(_this select 0) playActionNow (['gestureHi', 'gestureHiB', 'gestureHiC'] select (floor random 3));";
          showDisabled = 1;
          priority = 0.9;
          hotkey = "0";
        };
      };

      class AGM_Equipment {
        displayName = "$STR_AGM_Interaction_Equipment";
        condition = "true";
        statement = "";
        showDisabled = 1;
        priority = 4.5;
        icon = "";  // @todo
        subMenu[] = {"AGM_Equipment", 1};
        enableInside = 1;
        hotkey = "E";

        class AGM_Dummy {
          displayName = "";
          condition = "false";
          statement = "";
          showDisabled = 1;
          priority = -99;
          icon = "AGM_Core\UI\blank_CO.paa";
          enableInside = 1;
        };
      };
    };
  };

  class LandVehicle;
  class Car: LandVehicle {
    class AGM_Actions {};
    class AGM_SelfActions {};
  };
  class Tank: LandVehicle {
    class AGM_Actions {};
    class AGM_SelfActions {};
  };

  class Air;
  class Helicopter: Air {
    class AGM_Actions {};
    class AGM_SelfActions {};
  };
  class Plane: Air {
    class AGM_Actions {};
    class AGM_SelfActions {};
  };

  class Ship;
  class Ship_F: Ship {
    class AGM_Actions {
      class AGM_Push {
        displayName = "$STR_AGM_Interaction_Push";
        distance = 4;
        condition = "getMass AGM_Interaction_Target < 1000 and alive AGM_Interaction_Target";
        statement = "[AGM_Interaction_Target, [2 * (vectorDir _player select 0), 2 * (vectorDir _player select 1), 0.5]] call AGM_Interaction_fnc_push;";
        showDisabled = 0;
        priority = -1;
      };
    };
    class AGM_SelfActions {};
  };

  /*
  // BLUFOR Uniforms
  class SoldierWB: CAManBase {};
  class B_Soldier_base_F: SoldierWB {
    modelSides[] = {3,2,1,0};
    // allowedUniformSides = {3,2,1,0}; this doesn't seem to do anything (or i'm doing it wrong)
  };
  class B_Helipilot_F: B_Soldier_base_F {
    modelSides[] = {3,2,1,0};
  };
  class B_helicrew_F: B_Helipilot_F {
    modelSides[] = {3,2,1,0};
  };
  class B_Pilot_F: B_Helipilot_F {
    modelSides[] = {3,2,1,0};
  };
  class B_RangeMaster_F: B_Soldier_base_F {
    modelSides[] = {3,2,1,0};
  };
  class B_Soldier_02_f: B_Soldier_base_F {
    modelSides[] = {3,2,1,0};
  };
  class B_Soldier_03_f: B_Soldier_base_F {
    modelSides[] = {3,2,1,0};
  };
  class B_Soldier_04_f: B_Soldier_base_F {
    modelSides[] = {3,2,1,0};
  };
  class B_Soldier_05_f: B_Soldier_base_F {
    modelSides[] = {3,2,1,0};
  };
  class B_soldier_survival_F: B_Soldier_base_F {
    modelSides[] = {3,2,1,0};
  };
  class B_Story_Protagonist_F: B_Soldier_base_F {
    modelSides[] = {3,2,1,0};
  };
  class B_Story_SF_Captain_F: B_Soldier_base_F {
    modelSides[] = {3,2,1,0};
  };
  class B_Soldier_diver_base_F: B_Soldier_base_F {};
  class B_diver_F: B_Soldier_diver_base_F {
    modelSides[] = {3,2,1,0};
  };

  // INDEP / FIA Uniforms
  class SoldierGB: CAManBase {};
  class I_Soldier_base_F: SoldierGB {
    modelSides[] = {3,2,1,0};
  };
  class I_officer_F: I_Soldier_base_F {
    modelSides[] = {3,2,1,0};
  };
  class I_Soldier_03_f: I_Soldier_base_F {
    modelSides[] = {3,2,1,0};
  };
  class I_Soldier_04_f: I_Soldier_base_F {
    modelSides[] = {3,2,1,0};
  };
  class I_Soldier_diver_base_F: I_Soldier_base_F {};
  class I_diver_F: I_Soldier_diver_base_F {
    modelSides[] = {3,2,1,0};
  };

  class I_G_Soldier_base_F: SoldierGB {
    modelSides[] = {3,2,1,0};
  };
  class I_G_engineer_F: I_G_Soldier_base_F {}; // WHY BOHEMIA? WHY?
  class B_G_engineer_F: I_G_engineer_F {
    modelSides[] = {3,2,1,0};
  };
  class I_G_medic_F: I_G_Soldier_base_F {};
  class B_G_medic_F: I_G_medic_F {
    modelSides[] = {3,2,1,0};
  };
  class I_G_officer_F: I_G_Soldier_base_F {};
  class B_G_officer_F: I_G_officer_F {
    modelSides[] = {3,2,1,0};
  };
  class I_G_Soldier_A_F: I_G_Soldier_base_F {};
  class B_G_Soldier_A_F: I_G_Soldier_A_F {
    modelSides[] = {3,2,1,0};
  };
  class I_G_Soldier_AR_F: I_G_Soldier_base_F {};
  class B_G_Soldier_AR_F: I_G_Soldier_AR_F {
    modelSides[] = {3,2,1,0};
  };
  class I_G_Soldier_exp_F: I_G_Soldier_base_F {};
  class B_G_Soldier_exp_F: I_G_Soldier_exp_F {
    modelSides[] = {3,2,1,0};
  };
  class I_G_Soldier_F: I_G_Soldier_base_F {};
  class B_G_Soldier_F: I_G_Soldier_F {
    modelSides[] = {3,2,1,0};
  };
  class I_G_Story_SF_Captain_F: B_G_Soldier_F {
    modelSides[] = {3,2,1,0};
  };
  class I_G_Soldier_GL_F: I_G_Soldier_base_F {};
  class B_G_Soldier_GL_F: I_G_Soldier_GL_F {
    modelSides[] = {3,2,1,0};
  };
  class I_G_Soldier_LAT_F: I_G_Soldier_base_F {};
  class B_G_Soldier_LAT_F: I_G_Soldier_LAT_F {
    modelSides[] = {3,2,1,0};
  };
  class I_G_Soldier_lite_F: I_G_Soldier_base_F {};
  class B_G_Soldier_lite_F: I_G_Soldier_lite_F {
    modelSides[] = {3,2,1,0};
  };
  class I_G_Soldier_M_F: I_G_Soldier_base_F {};
  class B_G_Soldier_M_F: I_G_Soldier_M_F {
    modelSides[] = {3,2,1,0};
  };
  class I_G_Soldier_SL_F: I_G_Soldier_base_F {};
  class B_G_Soldier_SL_F: I_G_Soldier_SL_F {
    modelSides[] = {3,2,1,0};
  };
  class I_G_Soldier_TL_F: I_G_Soldier_base_F {};
  class B_G_Soldier_TL_F: I_G_Soldier_TL_F {
    modelSides[] = {3,2,1,0};
  };
  */

  class StaticWeapon: LandVehicle {
    class AGM_Actions {};
    class AGM_SelfActions {};
  };

  class StaticMortar;
  class Mortar_01_base_F: StaticMortar {
    class AGM_Actions {};
    class AGM_SelfActions {};
  };

  class Box_NATO_Support_F;
  class AGM_Box_Misc: Box_NATO_Support_F {
    class TransportItems {
      MACRO_ADDITEM(AGM_CableTie,24)
    };
  };
};

class CfgWeapons {
  class AGM_ItemCore;
  class InventoryItem_Base_F;

  class AGM_CableTie: AGM_ItemCore {
    displayName = "$STR_AGM_Interaction_CableTie_Name";
    descriptionShort = "$STR_AGM_Interaction_CableTie_Description";
    model = "\AGM_Interaction\agm_cabletie.p3d";
    picture = "\AGM_Interaction\UI\agm_cabletie_x_ca.paa";
    scope = 2;
    class ItemInfo: InventoryItem_Base_F {
      mass = 1;
    };
  };
};

#include <Menu_Config.hpp>
