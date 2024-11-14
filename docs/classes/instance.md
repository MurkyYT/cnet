# cnet::Instance

**Instance** is not really used, it is only used in the windows operating system to initialize WSA and cleanup after it.
Ideally should be called always just in case.

### Methods

<table>
<tr>
    <th>Name</th>
    <th>Description</th>
    <th>Return type</th>
</tr>
<tr>
 	<td>Initialize</td>
	<td>Initializes needed dll's/so's</td>
	<td>void</td>
</tr>
<tr>
 	<td>Uninitialize</td>
	<td>Cleans everything up</td>
	<td>void</td>
</tr>
</table>