#pragma once

/// <summary>
/// Connect to INO-BA Board
/// </summary>
/// <param name="IP">Board IP</param>
/// <param name="FWUpgradeNotRequired">Return If FW Upgrade required
///										True: Use GUI to Upgrade
///										False: Not Required
/// </param>
/// <returns>True: Connected, False: Error Connection
/// </returns>
bool __stdcall Connect(char* IP, bool* FWUpgradeNotRequired);

/// <summary>
/// Connect to INO-BA Board
/// </summary>
/// <param name="IP">Board IP</param>
/// <param name="FWStatus">Return If FW Upgrade required
///										2: Update API/GUI
///										1: Use GUI to Upgrade
///										0: Not Required
/// </param>
/// <returns>True: Connected, False: Error Connection
/// </returns>
bool __stdcall ConnectV2(char* IP, unsigned char* FWStatus);

/// <summary>
/// Connect to INO-BA Board
/// </summary>
/// <param name="IP">Board IP</param>
/// <param name="FWUpgradeNotRequired">Return If FW Upgrade required
///										2: Update API/GUI
///										1: Use GUI to Upgrade
///										0: Not Required
/// </param>
/// <param name="hwMajorVr">Hardware Major Revision Number</param>
/// <param name="hwMinorVr">Hardware Minor Revision Number</param>
/// <returns>True: Connected, False: Error Connection
/// </returns>
bool __stdcall ConnectV3(char* IP, unsigned char* FWStatus, unsigned char* hwMajorVr, unsigned char* hwMinorVr);

/// <summary>
/// Check If Connected
/// </summary>
/// <returns>True: Is Connected, False: Disconnected</returns>
bool __stdcall IsConnected();

/// <summary>
/// Test if Connection still working
/// </summary>
/// <returns>True: Is Connected, False: Disconnected</returns>
bool __stdcall HWIsConnected();

/// <summary>
/// Disconnect from INO-BA Board
/// </summary>
/// <returns>isDisconnected</returns>
bool __stdcall Disconnect();

/// <summary>
/// Change Machine IP (It will auto restart)
/// </summary>
/// <param name="IP">byte[4]  ex: { 172, 16, 80, 88 }</param>
/// <returns>True: Command Executed, False: Something Went Wrong</returns>
bool __stdcall ChangeIP(byte* IP);


/// <summary>
/// Switch On And Off PPG ED Options
/// </summary>
/// <param name="basic">Basic settings</param>
/// <param name="multiRate">Multi Rate option</param>
/// <param name="OneP5Vpp">One point five voltage option</param>
/// <param name="FEC">FEC option</param>
/// <param name="FiftyThreeG">53G option</param>
/// <param name="isPAM4">[Read Only] is PAM4 supported</param>
/// <param name="is8Ch">[Read Only] is the board 8 Channels or 4 Channels</param>
/// <returns>True: Command Executed, False: Something Went Wrong</returns>
bool __stdcall SwitchPPGEDOptions(bool* basic, bool* multiRate, bool* OneP5Vpp,
	bool* FEC, bool* FiftyThreeG, bool* isPAM4, bool* is8Ch);

/// <summary>
/// Switch On And Off PPG ED Options
/// </summary>
/// <param name="basic">Basic settings</param>
/// <param name="multiRate">Multi Rate option</param>
/// <param name="OneP5Vpp">One point five voltage option</param>
/// <param name="FEC">FEC option</param>
/// <param name="FiftyThreeG">53G option</param>
/// <param name="isPAM4">[Read Only] is PAM4 supported</param>
/// <param name="is8Ch">[Read Only] is the board 8 Channels or 4 Channels</param>
/// <param name="isMA">[Read Only] is MA</param>
/// <returns>True: Command Executed, False: Something Went Wrong</returns>
bool __stdcall SwitchPPGEDOptionsV2(bool* basic, bool* multiRate, bool* OneP5Vpp,
	bool* FEC, bool* FiftyThreeG, bool* isPAM4, bool* is8Ch, bool* isMA);

/// <summary>
/// Set DataRate
/// </summary>
/// <param name="isNRZ">True: NRZ, False: PAM4</param>
/// <param name="dataRate">
/// DataRate in MBd:
/// In NRZ:  28900000, 28050000, 26562500, 25781250,
///          24330240, 14025000, 12500000, 11317600,
///          10709000, 10312500, 9953280
/// In PAM4: 57800000, 53125000, 28900000, 28050000,
///          26562500
/// </param>
/// <param name="clockDiv">
/// 0 : Rate/8
/// 1 : Rate/16
/// 2 : Rate/32
/// 3 : Rate/64
/// </param>
/// <param name="rxSensitivity">
/// Select Sensitivity:
/// 0 : High Sensitivity
/// 1 : Optimized
/// 2 : High Power
/// </param>
/// <param name="ctle">CTLE in dB</param>
/// <returns>True: Command Executed, False: Something Went Wrong</returns>
bool __stdcall SetBAConfig(unsigned char signalMode, int dataRate,
	unsigned char clockDiv, unsigned char rxSensitivity, unsigned short ctle);

/// <summary>
/// Set DataRate
/// </summary>
/// <param name="isNRZ">True: NRZ, False: PAM4</param>
/// <param name="dataRate">
/// DataRate in MBd:
/// In NRZ:  28900000, 28050000, 26562500, 25781250,
///          24330240, 14025000, 12500000, 11317600,
///          10709000, 10312500, 9953280
/// In PAM4: 57800000, 53125000, 28900000, 28050000,
///          26562500
/// </param>
/// <param name="clockDiv">
/// 0 : Rate/8
/// 1 : Rate/16
/// 2 : Rate/32
/// 3 : Rate/64
/// </param>
/// <param name="rxSensitivity">
/// Select Sensitivity:
/// 0 : High Sensitivity
/// 1 : Optimized
/// 2 : High Power
/// </param>
/// <param name="ctle">CTLE in dB</param>
/// <param name="mapping">
/// 0 : Gray Mapping
/// 1 : Linear Mapping
/// </param>
/// <param name="reserved">
/// 0 : Off
/// 1 : On
/// </param>
/// <returns>True: Command Executed, False: Something Went Wrong</returns>
bool __stdcall SetBAConfigAdv(unsigned char signalMode, int dataRate,
	unsigned char clockDiv, unsigned char rxSensitivity, unsigned short ctle,
	unsigned char mapping, unsigned char reserved);

/// <summary>
/// Set DataRate
/// </summary>
/// <param name="isNRZ">True: NRZ, False: PAM4</param>
/// <param name="dataRate">
/// DataRate in MBd:
/// In NRZ:  28900000, 28050000, 26562500, 25781250,
///          24330240, 14025000, 12500000, 11317600,
///          10709000, 10312500, 9953280
/// In PAM4: 57800000, 53125000, 28900000, 28050000,
///          26562500
/// </param>
/// <param name="clockDiv">
/// 0 : Rate/8
/// 1 : Rate/16
/// 2 : Rate/32
/// 3 : Rate/64
/// </param>
/// <param name="rxSensitivity">
/// Select Sensitivity:
/// 0 : High Sensitivity
/// 1 : Optimized
/// 2 : High Power
/// </param>
/// <param name="ctle">CTLE in dB</param>
/// <param name="mapping">
/// 0 : Gray Mapping
/// 1 : Linear Mapping
/// </param>
/// <param name="reserved">
/// 0 : Off
/// 1 : On
/// </param>
/// <param name = "PPMTuneVal">Data - rate PPM Tune(+-300ppm, +-200ppm, +-100ppm, 0 ppm < / param>
/// <returns>True: Command Executed, False: Something Went Wrong</returns>
bool __stdcall SetBAConfigAdvV2(unsigned char signalMode, int dataRate,
	unsigned char clockDiv, unsigned char rxSensitivity, unsigned short ctle,
	unsigned char mapping, unsigned char reserved, unsigned short PPMTuneVal);

/// <summary>
/// Set TX/RX Pattern
/// </summary>
/// <param name="channelIndex">0: All Or Channel Index</param>
/// <param name="patternSelect">
/// Select Pattern:
/// NRZ:  PN7:0, SSPRQ:1, PN9:2 PN11:3, PN13:4 PN15:5, PN16:6, PN23:7, PN31:8
/// PAM4: PN7Q:10, SSPRQ:11 PN9Q:12 PN11Q:13, PN13Q:14, PN15Q:15, PN16Q:16, PN23Q:17, PN31Q:18
/// User Pattern: 9
/// </param>
/// <param name="userPattern"> Not Implemented Yet</param>
/// <param name="isAutoLock">True: AutoLock, False: AutoLock Off</param>
/// <param name="fecType">
/// Select Pattern:
/// NRZ:  Single KR4:0, Combined KR4:1
/// PAM4: Single KP4:2, Combined KP4:3
/// </param>
/// <returns>True: Command Executed, False: Something Went Wrong</returns>
bool __stdcall SetPattern(unsigned char channelIndex,
	unsigned char patternSelect,
	unsigned long long userPattern,
	bool isAutoLock,
	unsigned char fecType);

/// <summary>
/// Set RX Pattern
/// </summary>
/// <param name="channelIndex">0: All Or Channel Index</param>
/// <param name="patternSelect">
/// Select Pattern:
/// NRZ:  PN7:0, PN9:2 PN11:3, PN13:4 PN15:5, SSPRQ:6, PN23:7, PN31:8
/// PAM4: PN7Q:10, PN9:12 PN11:13, PN13:14, PN15:15, SSPRQ:16, PN23:17, PN31:18
/// </param>
/// <param name="isAutoLock">True: AutoLock, False: AutoLock Off</param>
/// <param name="fecType">
/// Select Pattern:
/// NRZ:  Single KR4:0, Combined KR4:1
/// PAM4: Single KP4:2, Combined KP4:3
/// </param>
/// <returns>True: Command Executed, False: Something Went Wrong</returns>
bool __stdcall SeRXPattern(unsigned char channelIndex,
	unsigned char patternSelect,
	bool isAutoLock,
	unsigned char fecType);

/// <summary>
/// Set Taps
/// </summary>
/// <param name="channelIndex">0: All Or Channel Index</param>
/// <param name="pre">Pre-Cursor -100% to +100%</param>
/// <param name="main">Main Cursor 0-1000 mV (1500 is 1.5V Mode</param>
/// <param name="post">Post-Cursor -100% to +100%</param>
/// <param name="upperEyeHeight">Upper Eye Height -100% to +100%</param>
/// <param name="lowerEyeHeight">Lower Eye Height -100% to +100%</param>
/// <returns>True: Command Executed, False: Something Went Wrong</returns>
bool __stdcall UpdateTaps(byte channelIndex,
	double pre, double main, double post,
	double upperEyeHeight, double lowerEyeHeight);


/// <summary>
/// Set Taps
/// </summary>
/// <param name="channelIndex">Channel Index Select</param>
/// <param name="pre">Precursor -100% to +100%</param>
/// <param name="main">Main Cursor 0-1000 mV (1500 in 1.5V Mode</param>
/// <param name="post">Post-cursor -100% to +100%</param>
/// <param name="upperEyeHeight">Upper Eye Height -100% to +100%</param>
/// <param name="lowerEyeHeight">Lower Eye Height -100% to +100%</param>
/// <returns>True: Command Executed, False: Something Went Wrong</returns>
bool __stdcall Update7Taps(
	byte channelIndex,
	double pre1, double pre2, double pre3, double main,
	double post1, double post2, double post3,
	double upperEyeHeight, double lowerEyeHeight);

/// <summary>
/// Set CTLE Per Channel
/// </summary>
/// <param name="channelIndex">0: All Or Channel Index</param>
/// <param name="ctleValue">CTLE Value in dB 0-8</param>
/// <returns>True: Command Executed, False: Something Went Wrong</returns>
bool __stdcall SetCTLE(byte channelIndex,
	unsigned short ctleValue);

/// <summary>
/// Set RX Sensitivity
/// </summary>
/// <param name="channelIndex">0: All Or Channel Index</param>
/// <param name="rxSensitivity">
/// Select Sensitivity:
/// 0 : High Sensitivity
/// 1 : Optimized
/// 2 : High Power
/// </param>
/// <returns>True: Command Executed, False: Something Went Wrong</returns>
bool __stdcall SetRXSensitivity(byte channelIndex,
	byte rxSensitivity);


/// <summary>
/// Set BER Settings
/// </summary>
/// <param name="channelIndex">0: All Or Channel Index</param>
/// <param name="BERTType">0: Timed, 1: Repetitive, 2: Infinite</param>
/// <param name="realtimeUpdate">True: Update ReadBERStat every 1s, False: Update ReadBERState on Timer finish</param>
/// <param name="days">Counter Days</param>
/// <param name="hours">Counter Hours</param>
/// <param name="minutes">Counter Minutes</param>
/// <param name="seconds">Counter Seconds</param>
/// <returns>True: Command Executed, False: Something Went Wrong</returns>
bool __stdcall SetBERSettings(byte channelIndex, byte BERTType, bool realtimeUpdate,
	int days, int hours, int minutes, int seconds);

/// <summary>
/// Start BER Test
/// </summary>
/// <returns>True: Command Executed, False: Something Went Wrong</returns>
bool __stdcall StartBERTest();


/// <summary>
/// Stop BER Test
/// </summary>
/// <returns>True: Command Executed, False: Something Went Wrong</returns>
bool __stdcall StopBERTest();

/// <summary>
/// Is BER Test is running
/// </summary>
/// <returns>True: Still Running, False: Finished</returns>
bool __stdcall IsBERTRunning();

/// <summary>
/// Clear BER Results
/// </summary>
/// <param name="channelIndex">0: All Or Channel Index</param>
/// <returns>True: Command Executed, False: Something Went Wrong</returns>
bool __stdcall ClearBERTest(byte channelIndex);

/// <summary>
/// Read BER Test Result
/// </summary>
/// <param name="captureTimeIns">Capture Time in s ( date = capture time ins seconds since 1970)</param>
/// <param name="rxPatternMSB">RX Pattern Status MSB (Array[9]) Ch1 = array[1] ... Ch8 = array[8] </param>
/// <param name="rxPatternLSB">RX Pattern Status LSB (Array[9]) Ch1 = array[1] ... Ch8 = array[8]</param>
/// <param name="rxLockMSB">RX Lock Status MSB (Array[9]) 0 = LOL, 1 = Locked, 2 = LOS</param>
/// <param name="rxLockLSB">RX Lock Status LSB (Array[9]) 0 = LOL, 1 = Locked, 2 = LOS</param>
/// <param name="rxInvertMSB">RX Invert Status MSB (Array[9]) Ch1= array[1],..</param>
/// <param name="rxInvertLSB">RX Invert Status LSB (Array[9]) Ch1= array[1],..</param>
/// <param name="bertErrorCountMSB">MSB Error Count Detected (Array[9]) Ch1 = array[1] ... Ch8 = array[8].</param>
/// <param name="bertErrorCountLSB">LSB Error Count Detected (Array[9])Ch1 = array[1] ... Ch8 = array[8]</param>
/// <param name="bertErrorCount">Sum of Error Count Detected (Array[9]) Ch1 = array[1] ... Ch8 = array[8]</param>
/// <param name="bertBitCount">Number of bits counted (Array[9]) Ch1= array[1],..</param>
/// <param name="realTimer">Real BER Timer based on Captured Bits in seconds (Array[9]) Ch1 = array[1] ... Ch8 = array[8]</param>
/// <param name="bertValue">BER Test Results (Array[9]) Ch1= array[1],..</param>
///////////////////////////////////////////////////////////////////////////////////
/// ONLY when FEC option is enabled
/// <param name="fecCOR">FEC Correctable Errors (Array[9]) Ch1 = array[1] ... Ch8 = array[8].</param>
/// <param name="fecBertValues">BER Test Results After Correction (Array[9]) Ch1 = array[1] ... Ch8 = array[8]</param>
/// <param name="fecResults">Detailed FEC Results (Array[432])
/// Array is partitioned by 48 per block, each block is assigned to a channel
/// Ch1 index start from array[48]. array[48] = 1 Symbol Error, ... Array[79] = 31 Symbol Error, Array[80] = OverFlow.
/// ....
/// Ch8 index start from array[384]. array[384] = 1 Symbol Error, ... Array[415] = 31 Symbol Error, Array[416] = OverFlow.
/// </param>
/// <returns>False: Still running wait timeout, True: Test Completed</returns>
bool __stdcall ReadBERResult(
	long* captureTimeIns,
	byte* rxPatternMSB,
	byte* rxPatternLSB,
	byte* rxLockMSB,
	byte* rxLockLSB,
	byte* rxLock,
	byte* rxInvertMSB,
	byte* rxInvertLSB,
	unsigned long long* bertErrorCountMSB,
	unsigned long long* bertErrorCountLSB,
	unsigned long long* bertErrorCount,
	unsigned long long* bertBitCount,
	double* realTimer,
	double* bertValues,
	unsigned long long* fecCOR,
	double* fecBertValues,
	unsigned long long* fecResults
);


/// <summary>
/// Read BER Test Result
/// </summary>
/// <param name="captureTimeIns">Capture Time in s ( date = capture time ins seconds since 1970)</param>
/// <param name="rxPatternMSB">RX Pattern Status MSB (Array[9]) Ch1 = array[1] ... Ch8 = array[8]</param>
/// <param name="rxPatternLSB">RX Pattern Status LSB (Array[9]) Ch1 = array[1] ... Ch8 = array[8]</param>
/// <param name="rxLockMSB">RX Lock Status MSB (Array[9]) 0 = LOL, 1 = Locked, 2 = LOS</param>
/// <param name="rxLockLSB">RX Lock Status LSB (Array[9]) 0 = LOL, 1 = Locked, 2 = LOS</param>
/// <param name="rxInvertMSB">RX Invert Status MSB (Array[9]) Ch1 = array[1] ... Ch8 = array[8]</param>
/// <param name="rxInvertLSB">RX Invert Status LSB (Array[9]) Ch1 = array[1] ... Ch8 = array[8]</param>
/// <param name="bertErrorCountMSB">MSB Error Count Detected (Array[9]) Ch1 = array[1] ... Ch8 = array[8]</param>
/// <param name="bertErrorCountLSB">LSB Error Count Detected (Array[9]) Ch1 = array[1] ... Ch8 = array[8]</param>
/// <param name="bertErrorCount">Sum of Error Count Detected (Array[9]) Ch1 = array[1] ... Ch8 = array[8]</param>
/// <param name="bertBitCount">Number of bits counted (Array[9]) Ch1 = array[1] ... Ch8 = array[8]</param>
/// <param name="realTimer">Real BER Timer based on Captured Bits in seconds (Array[9]) Ch1 = array[1] ... Ch8 = array[8]</param>
/// <param name="bertValue">BER Test Results (Array[9]) Ch1 = array[1] ... Ch8 = array[8]</param>
///////////////////////////////////////////////////////////////////////////////////
/// ONLY when FEC option is enabled
/// <param name="fecCOR">FEC Correctable Errors (Array[9]) Ch1 = array[1] ... Ch8 = array[8]</param>
/// <param name="fecBertValues">BER Test Results After Correction (Array[9]) Ch1 = array[1] ... Ch8 = array[8]</param>
/// <param name="fecResults">Detailed FEC Results (Array[432])
/// Array is partitioned by 48 per block, each block is assigned to a channel
/// Ch1 index start from array[48]. array[48] = 1 Symbol Error, ... Array[79] = 31 Symbol Error, Array[80] = OverFlow.
/// ....
/// Ch8 index start from array[384]. array[384] = 1 Symbol Error, ... Array[415] = 31 Symbol Error, Array[416] = OverFlow.
/// </param>
/// <param name="margin">Margin (Array[9]) Ch1 = array[1] ... Ch8 = array[8]</param>
/// <param name="MarginPct">Margin Percentage(Array[9]) Ch1 = array[1] ... Ch8 = array[8]</param>
/// <param name="UI">Ch Response UI(Array[90])</param>
/// Array is partitioned by 10 per block, each block is assigned to a channel
/// Ch1 index start from array[10]. array[10] = UI-1, ... Array[19] = UI-10
/// ....
/// Ch8 index start from array[80]. array[80] = UI-1, ... Array[89] = UI-10
/// </param>
/// <returns>False: Still running wait timeout, True: Test Completed</returns>
bool __stdcall ReadBERResultMargin(
	long* captureTimeIns,
	byte* rxPatternMSB,
	byte* rxPatternLSB,
	byte* rxLockMSB,
	byte* rxLockLSB,
	byte* rxLock,
	byte* rxInvertMSB,
	byte* rxInvertLSB,
	unsigned long long* bertErrorCountMSB,
	unsigned long long* bertErrorCountLSB,
	unsigned long long* bertErrorCount,
	unsigned long long* bertBitCount,
	double* realTimer,
	double* bertValues,
	unsigned long long* fecCOR,
	double* fecBertValues,
	unsigned long long* fecResults,
	double* margin,
	double* marginPct,
	char* UI
);



/// <summary>
/// Read BER Test Result
/// </summary>
/// <param name="captureTimeIns">Capture Time in s ( date = capture time ins seconds since 1970)</param>
/// <param name="rxPatternMSB">RX Pattern Status MSB (Array[9]) Ch1 = array[1] ... Ch8 = array[8]</param>
/// <param name="rxPatternLSB">RX Pattern Status LSB (Array[9]) Ch1 = array[1] ... Ch8 = array[8]</param>
/// <param name="rxLockMSB">RX Lock Status MSB (Array[9]) 0 = LOL, 1 = Locked, 2 = LOS</param>
/// <param name="rxLockLSB">RX Lock Status LSB (Array[9]) 0 = LOL, 1 = Locked, 2 = LOS</param>
/// <param name="rxInvertMSB">RX Invert Status MSB (Array[9]) Ch1 = array[1] ... Ch8 = array[8]</param>
/// <param name="rxInvertLSB">RX Invert Status LSB (Array[9]) Ch1 = array[1] ... Ch8 = array[8]</param>
/// <param name="bertErrorCountMSB">MSB Error Count Detected (Array[9]) Ch1 = array[1] ... Ch8 = array[8]</param>
/// <param name="bertErrorCountLSB">LSB Error Count Detected (Array[9]) Ch1 = array[1] ... Ch8 = array[8]</param>
/// <param name="bertErrorCount">Sum of Error Count Detected (Array[9]) Ch1 = array[1] ... Ch8 = array[8]</param>
/// <param name="bertBitCount">Number of bits counted (Array[9]) Ch1 = array[1] ... Ch8 = array[8]</param>
/// <param name="realTimer">Real BER Timer based on Captured Bits in seconds (Array[9]) Ch1 = array[1] ... Ch8 = array[8]</param>
/// <param name="bertValue">BER Test Results (Array[9]) Ch1 = array[1] ... Ch8 = array[8]</param>
///////////////////////////////////////////////////////////////////////////////////
/// ONLY when FEC option is enabled
/// <param name="fecCOR">FEC Correctable Errors (Array[9]) Ch1 = array[1] ... Ch8 = array[8]</param>
/// <param name="fecBertValues">BER Test Results After Correction (Array[9]) Ch1 = array[1] ... Ch8 = array[8]</param>
/// <param name="fecResults">Detailed FEC Results (Array[432])
/// Array is partitioned by 48 blocks, each block is assigned to a channel
/// Ch1 index start from array[48]. array[48] = 1 Symbol Error, ... Array[79] = 31 Symbol Error, Array[80] = OverFlow.
/// ....
/// Ch8 index start from array[384]. array[384] = 1 Symbol Error, ... Array[415] = 31 Symbol Error, Array[416] = OverFlow.
/// </param>
/// <param name="margin">Margin (Array[9]) Ch1 = array[1] ... Ch8 = array[8]</param>
/// <param name="MarginPct">Margin Percentage(Array[9]) Ch1 = array[1] ... Ch8 = array[8]</param>
/// <param name="UI">Ch Response UI(Array[144])
/// Array is partitioned by 16 per block, each block is assigned to a channel
/// Ch1 index start from array[10]. array[16] = UI-1, ... Array[31] = UI-16
/// ....
/// Ch8 index start from array[128]. array[80] = UI-1, ... Array[147] = UI-16
/// </param>
/// <returns>False: Still running wait timeout, True: Test Completed</returns>
bool __stdcall ReadBERResultMarginV2(
	long* captureTimeIns,
	byte* rxPatternMSB,
	byte* rxPatternLSB,
	byte* rxLockMSB,
	byte* rxLockLSB,
	byte* rxLock,
	byte* rxInvertMSB,
	byte* rxInvertLSB,
	unsigned long long* bertErrorCountMSB,
	unsigned long long* bertErrorCountLSB,
	unsigned long long* bertErrorCount,
	unsigned long long* bertBitCount,
	double* realTimer,
	double* bertValues,
	unsigned long long* fecCOR,
	double* fecBertValues,
	unsigned long long* fecResults,
	double* margin,
	double* marginPct,
	char* UI
);

/// <summary>
/// Re-lock All Channels
/// </summary>
/// <returns>True: Command Executed, False: Something Went Wrong</returns>
bool __stdcall Relock();

/// <summary>
/// Force Re-lock All Channels
/// </summary>
/// <returns>True: Command Executed, False: Something Went Wrong</returns>
bool __stdcall ForceRelock();

/// <summary>
/// Error Injection
/// </summary>
/// <param name="channelIndex">0: All Or Channel Index</param>
/// <param name="bitSelect">0: MSB, 1:LSB, 2:(MSB & LSB OR NRZ)</param>
/// <param name="type">0: Single Error Per Packet(64bit) 1: Burst Error Per Packet </param>
/// <param name="gap">0-127 Error Free Packets Gap between injected packets</param>
/// <param name="PktCount">0-127 Packet injected with Errors</param>
/// <returns>True: Command Executed, False: Something Went Wrong</returns>
bool __stdcall ErrorInjection(byte channelIndex,
	byte bitSelect, byte type, byte gap, byte PktCount);

/// <summary>
/// Read MA Power
/// <param name="voltage">Return Measured Voltage</param>
/// <param name="current">Return Measured Current</param>
/// </summary>
bool __stdcall ReadMAPower(double* voltage, double* current);

/// <summary>
/// Read MA Module IO Status
/// <param name="status">status[8]</param>
/// </summary>
bool __stdcall ReadMAModuleStatus(unsigned char* status);


/// <summary>
/// Read MA Module IO Status
/// <param name="status">status[8]</param>
/// </summary>
bool __stdcall ReadMAModuleStatus(unsigned char* status);


/// <summary>
/// Read Selected PPG Options
/// </summary>
/// <param name="basic">Basic settings</param>
/// <param name="multiRate">Multi Rate option</param>
/// <param name="OneP5Vpp">One point five voltage option</param>
/// <param name="FEC">FEC option</param>
/// <param name="FiftyThreeG">53G option</param>
/// <param name="isPAM4">Is PAM4 supported</param>
/// <param name="is8Ch">Is the board 8 Channels or 4 Channels</param>
/// <param name="isMA">Is MA</param>
/// <returns>True: Command Executed, False: Something Went Wrong</returns>
bool __stdcall ReadSelectedPPGOptions(
	bool* basic, bool* multiRate, bool* OneP5Vpp,
	bool* FEC, bool* FiftyThreeG, bool* isPAM4, bool* is8Ch,
	bool* isMA);



/// <summary>
/// Set DataRate
/// </summary>
/// <param name="isNRZ">True: NRZ, False: PAM4</param>
/// <param name="dataRate">
/// DataRate in MBd:
/// In NRZ:  28900000, 28050000, 26562500, 25781250,
///          24330240, 14025000, 12500000, 11317600,
///          10709000, 10312500, 9953280
/// In PAM4: 57800000, 53125000, 28900000, 28050000,
///          26562500
/// </param>
/// <param name="clockDiv">
/// 0 : Rate/8
/// 1 : Rate/16
/// 2 : Rate/32
/// 3 : Rate/64
/// 4 : Rate/2
/// 5 : Rate/4
/// </param>
/// <param name="rxSensitivity">
/// Select Sensitivity:
/// 0 : High Sensitivity
/// 1 : Optimized
/// 2 : High Power
/// </param>
/// <param name="ctle">CTLE in dB</param>
/// <param name="mapping">
/// 0 : Gray Mapping
/// 1 : Linear Mapping
/// </param>
/// <param name="reserved">
/// 0 : Off
/// 1 : On
/// </param>
/// <returns>True: Command Executed, False: Something Went Wrong</returns>
bool __stdcall ReadDataRate(unsigned char* signalMode, int* dataRate, unsigned char* clockDiv,
	unsigned char* mapping, unsigned char* coding);


/// <summary>
/// Read DataRate
/// </summary>
/// <param name="isNRZ">True: NRZ, False: PAM4</param>
/// <param name="dataRate">
/// DataRate in MBd:
/// In NRZ:  28900000, 28050000, 26562500, 25781250,
///          24330240, 14025000, 12500000, 11317600,
///          10709000, 10312500, 9953280
/// In PAM4: 57800000, 53125000, 28900000, 28050000,
///          26562500
/// </param>
/// <param name="clockDiv">
/// 0 : Rate/8
/// 1 : Rate/16
/// 2 : Rate/32
/// 3 : Rate/64
/// </param>
/// <param name="rxSensitivity">
/// Select Sensitivity:
/// 0 : High Sensitivity
/// 1 : Optimized
/// 2 : High Power
/// </param>
/// <param name="ctle">CTLE in dB</param>
/// <param name="mapping">
/// 0 : Gray Mapping
/// 1 : Linear Mapping
/// </param>
/// <param name="preCoding">
/// 0 : Off
/// 1 : On
/// </param>
/// <returns>True: Command Executed, False: Something Went Wrong</returns>
bool __stdcall ReadDataRateAdv(unsigned char* signalMode, int* dataRate, unsigned char* clockDiv,
	unsigned char* mapping, unsigned char* preCoding);

/// <summary>
/// Read Pattern Data
/// </summary>
bool __stdcall ReadPatternData(
	char* patternTX,
	double* preCursor,
	double* amplitude,
	double* postCursor,
	double* upperEyeHeight,
	double* lowerEyeHeight,
	char* txInvert,
	char* patternRX,
	char* patternRXLSB,
	bool* rxAutoLock,
	char* rxInvert,
	char* fecModeSelect,
	char* rxSensitivity,
	unsigned short* ctle);

/// <summary>
/// Read Pattern Data For 7 Taps
/// </summary>
bool __stdcall ReadPatternData7T(
	char* is7Taps,
	char* patternTX,
	double* preCursor1,
	double* preCursor2,
	double* preCursor,
	double* amplitude,
	double* postCursor,
	double* postCursor2,
	double* postCursor3,
	double* upperEyeHeight,
	double* lowerEyeHeight,
	char* txInvert,
	char* patternRX,
	char* patternRXLSB,
	bool* rxAutoLock,
	char* rxInvert,
	char* fecModeSelect,
	char* rxSensitivity,
	unsigned short* ctle);

/// <summary>
/// Read BER Test Result
/// </summary>
/// <param name="captureTimeIns">Capture Time in s ( date = capture time ins seconds since 1970)</param>
/// <param name="rxPatternMSB">RX Pattern Status MSB (Array[9]) Ch1 = array[1] ... Ch8 = array[8]</param>
/// <param name="rxPatternLSB">RX Pattern Status LSB (Array[9]) Ch1 = array[1] ... Ch8 = array[8]</param>
/// <param name="rxLockMSB">RX Lock Status MSB (Array[9]) 0 = LOL, 1 = Locked, 2 = LOS</param>
/// <param name="rxLockLSB">RX Lock Status LSB (Array[9]) 0 = LOL, 1 = Locked, 2 = LOS</param>
/// <param name="rxInvertMSB">RX Invert Status MSB (Array[9]) Ch1 = array[1] ... Ch8 = array[8]</param>
/// <param name="rxInvertLSB">RX Invert Status LSB (Array[9]) Ch1 = array[1] ... Ch8 = array[8]</param>
/// <param name="bertErrorCountMSB">MSB Error Count Detected (Array[9]) Ch1 = array[1] ... Ch8 = array[8]</param>
/// <param name="bertErrorCountLSB">LSB Error Count Detected (Array[9]) Ch1 = array[1] ... Ch8 = array[8]</param>
/// <param name="bertErrorCount">Sum of Error Count Detected (Array[9]) Ch1 = array[1] ... Ch8 = array[8]</param>
/// <param name="bertBitCount">Number of bits counted (Array[9]) Ch1 = array[1] ... Ch8 = array[8]</param>
/// <param name="realTimer">Real BER Timer based on Captured Bits in seconds (Array[9]) Ch1 = array[1] ... Ch8 = array[8]</param>
/// <param name="bertValue">BER Test Results (Array[9])</param>
///////////////////////////////////////////////////////////////////////////////////
/// ONLY when FEC option is enabled
/// <param name="fecCOR">FEC Correctable Errors (Array[9]) Ch1 = array[1] ... Ch8 = array[8]</param>
/// <param name="fecBertValues">BER Test Results After Correction (Array[9]) Ch1 = array[1] ... Ch8 = array[8]</param>
/// <param name="fecResults">Detailed FEC Results (Array[432])</param>
/// <param name="margin">Margin (Array[9])</param>
/// <param name="MarginPct">Margin Percentage(Array[9])</param>
/// <param name="UI">Ch Response UI(Array[90])</param>
/// <returns>False: Still running wait timeout, True: Test Completed</returns>
bool __stdcall ReadBERResultMarginVEE(
	int* captureTimeIns,
	int* rxPatternMSB,
	int* rxPatternLSB,
	int* rxLockMSB,
	int* rxLockLSB,
	int* rxLock,
	int* rxInvertMSB,
	int* rxInvertLSB,
	INT64* bertErrorCountMSB,
	INT64* bertErrorCountLSB,
	INT64* bertErrorCount,
	INT64* bertBitCount,
	double* realTimer,
	double* bertValues,
	INT64* fecCOR,
	double* fecBertValues,
	INT64* fecResults,
	double* margin,
	double* marginPct,
	int* UI
);

/// <summary>
/// MA Set Status on Screen
/// <param name="color">0: No Light, 1:Blue, 2:Yellow, 3:Green, 4:Red</param>
/// <param name="message">Message displayed on the screen (Array[6])</param>
/// </summary>
bool __stdcall MASetStatus(byte color, char* message);

/// <summary>
/// MA Set Message on Screen
/// <param name="line">Specify line 0, 1 or 2</param>
/// <param name="message">Message displayed on the screen (Array[14])</param>
/// </summary>
bool __stdcall MASetMessage(byte line, char* message);

/// <summary>
/// MA Set Power supply voltage output
/// <param name="enable">Enable power</param>
/// <param name="voltage">voltage output between 3.15-3.54</param>
/// </summary>
bool __stdcall MASetPower(bool enable, double voltage);

/// <summary>
/// MA Read Power setting and measured
/// <param name="isEnabled">Is power enabled</param>
/// <param name="voltageSet">Get target voltage</param>
/// <param name="voltage">Get measured voltage</param>
/// <param name="current">Get measured current</param>
/// </summary>
bool __stdcall MAGetPower(bool* isEnabled, double* voltageSet, double* voltage, double* current);

/// <summary>
/// MA Set I2C Speed
/// <param name="speedIndex">Speed mode: 0: 100KHz, 1:400KHz, 2:3.4MHz</param>
/// </summary>
bool __stdcall MAI2CSpeed(unsigned char speedIndex);

/// <summary>
/// MA I2C Read Current register set
/// <param name="val">Returned Value</param>
/// </summary>
bool __stdcall MAI2CReadCurrent(unsigned char* val);

/// <summary>
/// MA I2C read register value
/// <param name="adr">Set address register</param>
/// <param name="val">Returned register value</param>
/// </summary>
bool __stdcall MAI2CReadAdr(unsigned char adr, unsigned char* val);

/// <summary>
/// MA I2C read array register
/// <param name="adr">Set array of addresses Array[256]</param>
/// <param name="val">Return array of values Array[256]</param>
/// <param name="count">specify count of registers to read</param>
/// </summary>
bool __stdcall MAI2CReadArrayAdr(unsigned char* adr, unsigned char* val, unsigned char count);

/// <summary>
/// MA I2C read sequential register
/// <param name="adr">Set start address</param>
/// <param name="val">Return array of values Array[256]</param>
/// <param name="count">specify count of registers to read</param>
/// </summary>
bool __stdcall MAI2CReadSeq(unsigned char adr, unsigned char* val, unsigned char count);

/// <summary>
/// MA I2C write register value
/// <param name="adr">Set address register</param>
/// <param name="val">Set register value</param>
/// </summary>
bool __stdcall MAI2CWriteAdr(unsigned char adr, unsigned char val);

/// <summary>
/// MA I2C write array register
/// <param name="adr">Set array of addresses Array[256]</param>
/// <param name="val">Set array of values Array[256]</param>
/// <param name="count">specify count of registers to write</param>
/// </summary>
bool __stdcall MAI2CWriteArrayAdr(unsigned char* adr, unsigned char* val, unsigned char count);

/// <summary>
/// MA I2C write sequential register
/// <param name="adr">Set start address</param>
/// <param name="val">Set array of values Array[256]</param>
/// <param name="count">specify count of registers to read</param>
/// </summary>
bool __stdcall MAI2CWriteSeq(unsigned char adr, unsigned char* val, unsigned char count);

/// <summary>
/// MA I2C write array register
/// <param name="op"> 0:Write register, 1:Read register</param>
/// <param name="adr">Array of addresses Array[256]</param>
/// <param name="val">Array of values Array[256]</param>
/// <param name="count">specify count of registers to write</param>
/// </summary>
bool __stdcall MAI2CWRArray(unsigned char* op, unsigned char* adr, unsigned char* val, unsigned char count);

/// <summary>
/// MA IO Control
/// <param name="op"> 0:Write register, 1:Read register</param>
/// <param name="index"> (write) 1:ModSelL, 2:ResetL, 3:LPMode
///			 (read)  0:ModPrsL, 1:IntL
///</param>
/// </summary>
bool __stdcall MAIOControl(bool op, unsigned char index, unsigned char* val);

/// <summary>
/// PPM Tune || Re-lock is Required when wide range tuning is applied
/// <param name="isWrite">True: Read, False: Write</param>
/// <param name="ppmValue">Data-rate PPM Tune (+-300ppm, +-200ppm, +-100ppm, 0 ppm </param>
/// </summary>
bool __stdcall PPMTune(bool read, short* ppmValue);