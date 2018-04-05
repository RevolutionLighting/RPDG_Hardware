'This script renumbers all currently selected components.
'User can select a component prefix and starting sequence number.

'The program will work with all selected parts in original alphanumeric part number order.
'All parts will be given the new prefix and will be will be numbered sequentially, starting with the starting number entered..

'A list of changed part numbers is generated.

Sub Main
	Begin Dialog UserDialog 440,182,"Move Part Numbers Up",.CallbackFunc ' %GRID:10,7,1,1
		Text 40,14,350,21,"This program renumbers all selected parts sequentially. ",.Text1
		Text 100,105,210,21,"Hit OK to start or Close to quit.",.Text2
		Text 40,42,210,14,"Enter new Part # Prefix to use",.Text3
		Text 40,70,210,14,"Enter new starting number",.Text4
		TextBox 250,35,140,21,.PartPrefix
		TextBox 250,70,140,21,.StartPNumber
		PushButton 250,140,90,21,"OK",.OKBtn 'Make sure this is th first button defined.
		PushButton 60,140,90,21,"Close",.CloseBtn
	End Dialog
	Dim dlg As UserDialog
	Retcode = Dialog(dlg) 
	If RetCode=1 Then	' This is first button defined in the dialog box above - OK Button
		Prefix$ = dlg.PartPrefix
		StartNum=dlg.StartPNumber
		MsgBox "Renumbering all selected parts. Starting Component: " + Prefix$ + StartNum 
		PartsChanged=ChangePartNumbers( Prefix$, StartNum)
		If PartsChanged=0 Then
			MsgBox "No parts selected.  No parts changed or all part numbers are already in use."
		End If
	End If
	
End Sub


Rem See DialogFunc help topic for more information.
Private Function CallbackFunc(DlgItem$, Action%, SuppValue%) As Boolean
'Dim Pnum$ As String

	Select Case Action%
	Case 1 ' Dialog box initialization
		DlgText "PartPrefix", ""
		DlgText "StartPNumber", "500"
		
	Case 2 ' Value changing or button pressed
		If DlgItem$ = "OKBtn" Then
'       CallbackFunc = False	'Exit dialog box.  Not needed.  Automatically exits.
		End If

'		If DlgItem$ = "CloseBtn" Then
'			CallbackFunc = False	'Exit dialog box.  Not needed.  Automatically exits.
'		End If
		
	Case 3 ' TextBox or ComboBox text changed
		CallbackFunc = True ' Do not exit

	Case 4 ' Focus changed
	
	Case 5 ' Idle
		Rem CallbackFunc = True ' Continue getting idle actions
	End Select
End Function

Function ChangePartNumbers (Prefix$,StartNum) As Integer
	PartsChanged=0
	fname = ActiveDocument
	If fname = "" Then
		fname = "Untitled"
	End If
	tempFile = DefaultFilePath & "\temp.txt"
	Open tempFile For Output As #1
	'Output report header
	Print #1, "Part Number Changes for "; fname; " on "; Now
	Print #1

	StatusBarText = "Changing Parts..."
'	Print #1, "Name";vbTab;"Type";vbTab;"Logic";vbTab;"TypeObj"
	CurNum=StartNum
	For Each part In ActiveDocument.Components
'		Print #1, "Name";vbTab;"Type";vbTab;"Logic";vbTab;"TypeObj"
		If part.selected  Then
 			NewPartNum$=Prefix$+CurNum
			OldPartName=part.Name
			Print #1, part.Name;vbTab;
			Print #1, part.PartType;vbTab;
			On Error GoTo ErrProc
				part.Name=NewPartNum$
			On Error GoTo 0
			Print #1, "Changed to: ";
			Print #1, NewPartNum$

			PartsChanged=PartsChanged+1
EndOfPart:
			CurNum=CurNum+1
	End If		
'		Print #1

'		Print #1, "	Part Attributes:"
'		For Each attr In part.Attributes
'			Print #1, vbTab; attr.Name; "	=	"; attr.Value
'		Next
'		Print #1
'
	Next part

Print #1
	Print #1, "Total part numbers changed: "; PartsChanged
	StatusBarText = ""
	Close #1
	If PartsChanged>0 Then
		FillClipboard
		App = Shell ("Notepad", 1)
		AppActivate App
		SendKeys "+{Ins}" 'Shift-Ins  Paste
		SendKeys "^{Home}" 'Ctrl+Home  Go to top of the document
	End If
	ChangePartNumbers=PartsChanged	
Exit Function
	
ErrProc:
	Print #1, " ***Not Changed ***  Part number: ";NewPartNum$;" already in use."
Resume EndOfPart

End Function


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
