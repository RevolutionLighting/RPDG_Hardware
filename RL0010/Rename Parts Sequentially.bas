'Rename Parts Sequentially
'This script renumbers parts sequentially one by one.
'Functions like pin renumbering.

'1.  Enter a component prefix and starting sequence number.
'2.  Click on one at a time to renumber
'3.  The program then renumbers each part sequentially (with the same prefixes).
'4.  Change Prefix or Starting Number if you need to start a new sequence
'5.  Hit Close when done.
'6.  If any changes are made, a list of changed part numbers is generated.


Private  PartsChanged As Integer

Sub Main
	PartsChanged=0

' Define the dialog box ************************
' Set it up using callback function so that it will stay on screen
' while usere selects parts manually….
	Begin Dialog UserDialog 440,336,"Renumber Parts Sequentially",.CallbackFunc ' %GRID:10,7,1,1
		Text 40,14,350,21,"This program renumbers all selected parts sequentially. ",.Text1
		Text 150,133,120,14,"Hit Close to end.",.Text2
		Text 70,112,330,14,"Select parts individually with mouse to renumber.",.Text5
		Text 40,42,210,14,"Enter new Part # Prefix to use",.Text3
		Text 40,70,210,14,"Enter new starting number",.Text4
		TextBox 250,35,140,21,.PartPrefix
		TextBox 250,70,140,21,.StartPNumber
		PushButton 160,287,90,21,"Close",.CloseBtn
		Text 190,175,170,14,"OldNum",.OldNum
		Text 190,217,170,14,"NewNum",.NewNum
		Text 190,252,170,14,"PartsChanged",.PartsChanged
		Text 50,175,130,14,"Old Part Number:",.Text8
		Text 50,217,130,14,"New Part Number:",.Text7
		Text 80,196,130,14,"Changed to:",.Text10
		Text 50,252,130,14,"Parts Changed:",.Text9
	End Dialog

' Open the Dialog Box ***************************
' All the real work is done in the Callback function.
' (Actually in the Idle loop)
	Dim dlg As UserDialog
	Dialog dlg	
	Close #1 
	If  PartsChanged<>0 Then
		FillClipboard
		App = Shell ("Notepad", 1)
		AppActivate App
		SendKeys "+{Ins}" 'Shift-Ins  Paste
		SendKeys "^{Home}" 'Ctrl+Home  Go to top of the document
	End If
	
End Sub


' See DialogFunc help topic for more information.

' The Callback function where the real work gets done ********

Private Function CallbackFunc(DlgItem$, Action%, SuppValue%) As Boolean
Static PrevPartName$ 
Static CurNum As Integer
Static Prefix$

	Select Case Action%
	Case 1 ' Dialog box initialization
		DlgText "PartPrefix", ""
		DlgText "StartPNumber", "100"
		'First de-select all parts
		For Each part In ActiveDocument.Components		
			part.selected=False
		Next part		
		PrevPartName$=""
		PartsSelected=0
		fname = ActiveDocument
		If fname = "" Then
			fname = "Untitled"
		End If
	tempFile = DefaultFilePath & "\temp.txt"
	Open tempFile For Output As #1

	Case 2 ' Value changing or button pressed
		If DlgItem$  = "CloseBtn"  Then
			Print #1
			Print #1, "Total number of parts changed: "; PartsChanged
			CallbackFunc = False	'Exit dialog box.  Only needed when no statements in this case.
		End If

	Case 3 ' TextBox or ComboBox text changed
		CallbackFunc = True ' Do not exit
		
	Case 4 ' Focus changed
	
	Case 5 ' Idle
	'	MsgBox "In Idle" 
	' There may be an easier and faster way to do this rather than looping
	' through all the parts.  
		For Each part In ActiveDocument.Components		
			If part.selected And part.Name<>PrevPartName$ Then
				PrevPartName$=part.Name 'for comparison next time through the idle loop
				OldPartName$=part.Name  'for text display
				'StatusBarText = "Selected Part: " + part.Name
				'ChangePart part.Name=NewName$
				CurNum= DlgText("StartPNumber")
				Prefix$=DlgText("PartPrefix")
 				NewPartNum$=Prefix$ & CurNum
				Print #1, part.Name;vbTab;
				Print #1, part.PartType;vbTab;
				On Error GoTo ErrProc
				part.Name=NewPartNum$
				On Error GoTo 0
				PrevPartName$=part.Name
				StatusBarText = part.Name +" changed to: " +part.Name
				Print #1, "Changed to: ";
				Print #1, NewPartNum$
				DlgText "OldNum", OldPartName$
				DlgText "NewNum", NewPartNum$
				PartsChanged=PartsChanged+1
				DlgText "PartsChanged", CStr(PartsChanged)		

EndOfPart:
				CurNum=CurNum+1
				DlgText "StartPNumber", CStr(CurNum)		
			End If
		Next part
		CallbackFunc = True ' Continue getting idle actions
	End Select
Exit Function

ErrProc:
	Beep
	StatusBarText = OldPartNum$ + "Not changed."
	Print #1, OldPartNum$; " ***Not Changed ***  Part number: ";NewPartNum$;" already in use."
Resume EndOfPart

End Function

' FillClipboard generates a list of changed parts
Sub FillClipboard
	StatusBarText = "Export Data To Clipboard..."
	' Load whole file to string variable    
	tempFile = DefaultFilePath & "\temp.txt"
	Open tempFile  For Input As #1
	L = LOF(1)
	AllData$ = Input$(L,1)
	Close #1
	'Copy whole data to clipboard
	Clipboard AllData$ 
	Kill tempFile
	StatusBarText = ""
End Sub
