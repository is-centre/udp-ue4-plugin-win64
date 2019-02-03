# UDPCommunication for UE4 #

UDPCommunication is a plugin for UE4 that implements simple UDP communication. It is very simple and lightweight, but can be used for demanding applications like real-time communication.

In Alpha Control Lab (https://a-lab.ee/) and Re:creation VR&AR Lab (https://recreation.ee/) the plugin is used primarily for real-time communication with MATLAB/Simulink software.

Application example: https://recreation.ee/r/about/2018-11-ut/02/

## Installation and usage ##

See these videos:
* https://www.youtube.com/watch?v=db6Myy9R2OI (for UE4.17 and UE4.21 only atm!)
* https://www.youtube.com/watch?v=Avj8T6RGyPo


Quick rundown:
* Create a **Plugins** folder in your UE4 project root. The plugin can be used even in case of purely blueprint-based projects.
* Copy the UDPCommunication folder from **4.xx** into the new folder where **xx** is your UE4.xx engine version.
* The plugin is automatically activated and its contents can now be used.
* Create an **Actor** blueprint. In the parent class field, choose either UDPReceiver or UDPSender depending on what you intend to use the plugin for.
* Using the reference to the new blueprint instance, initialize the UDP socket in, e.g., Level Blueprint.
* Use the receive/send functions, break the incoming data as needed, use it in your new Actor blueprint.

## Next steps ##

* Clean up repo, setup a pipeline for releases.
* Documentation!

## Credits ##

Original code: UE4 user Rama (see https://wiki.unrealengine.com/UDP_Socket_Sender_Receiver_From_One_UE4_Instance_To_Another)

Update for real-time communication: Ralf Anari, TalTech University

Plugin format and packaging: Aleksei Tepljakov, TalTech University