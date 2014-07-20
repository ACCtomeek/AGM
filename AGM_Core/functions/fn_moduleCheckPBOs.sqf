/*
 * Author: KoffeinFlummi
 *
 * Initializes the check-PBOs module.
 *
 * Arguments:
 * Whatever the module provides. (I dunno.)
 *
 * Return Value:
 * None
 */

_logic = _this select 0;
_units = _this select 1;
_activated = _this select 2;

if !(_activated) exitWith {};

_mode = parseNumber (_logic getVariable "Action");

if (!isServer) then {
	_mode spawn {
		_mode = _this;

		waitUntil {
			sleep 1;
			!isNil "AGM_Version_ClientErrors"}
		};

		AGM_Version_Errors = [_missingAddon, _missingAddonServer, _oldVersionClient, _oldVersionServer];

		_missingAddon = _this select 0;
		_missingAddonServer = _this select 1;
		_oldVersionClient = _this select 2;
		_oldVersionServer = _this select 3;

		// Display error message.
		if (_missingAddon || {_missingAddonServer} || {_oldVersionClient} || {_oldVersionServer}) then {
			_text = "AGM version mismatch:<br/><br/>";
			_error = format ["AGM version mismatch: %1: ", profileName];

			if (_missingAddon) then {
				_text = _text + "Detected missing addon on client<br/>";
				_error = _error + "Missing file(s); ";
			};
			if (_missingAddonServer) then {
				_text = _text + "Detected missing addon on server<br/>";
				_error = _error + "Additional file(s); ";
			};
			if (_oldVersionClient) then {
				_text = _text + "Detected old client version<br/>";
				_error = _error + "Older version; ";
			};
			if (_oldVersionServer) then {
				_text = _text + "Detected old server version<br/>";
				_error = _error + "Newer version; ";
			};

			[_error, "{systemChat _this}"] call AGM_Core_fnc_execRemoteFnc;

			_text = composeText [lineBreak, parseText format ["<t align='center'>%1</t>", _text]];

			_rscLayer = "AGM_RscErrorHint" call BIS_fnc_rscLayer;
			_rscLayer cutRsc ["AGM_RscErrorHint", "PLAIN", 0, true];

			disableSerialization;
			_ctrlHint = uiNamespace getVariable "AGM_ctrlErrorHint";
			_ctrlHint ctrlSetStructuredText _text;

			if (_mode == 0) then {
				sleep 10;
				_rscLayer cutFadeOut 0.2;
			};

			if (_mode == 2) then {
				sleep 10;
				waitUntil {alive player};
				[player] call AGM_Core_fnc_adminKick;
			};
		};
	};
};

diag_log text "AGM: Check-PBOs Module Initialized.";
