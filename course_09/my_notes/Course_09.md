# Revision of Networks Part I

Network: is a group of connected computers and devices.
Ethernet: rules that computers follow for communicating on a wired network.
Wireless: rules that computers follow for communicating through a radio signals.
	Wi-Fi(Wireless Fidelity) is a popular way to connect wirelessly to a network.
Protocol: is a standard set of rules for how devices communicate through wires or wirelessly.

Questions:
- What is network?
> Connected devices.

- Why do we need network?
> To be able to share data.

- What is LAN and WAN?
> LAN is a small network, I mean small number of connected devices.
> WAN is larger than LAN. We can make a WAN by connecting LANs together.

- How computers communicate together?
> They can communicate wirely, and they use the Ethernet protocol to do so.
> And they can communicate wirelessly, they can use the wifi to do so, I'm not sure if the wifi is a protocol, but it is a way we use to connect devices together wirelessly.
> If we connect the devices together through the wifi, then, they can share data.

- What is Ethernet?
> It is a set of rules the devices follow to communicate through wires.

- What is Wireless?
> Where the devices can share data and communicate without wires.

- What is Protocol?
> Is a standard rules the devices follow in order to communicate wirely/wirelessly.

- What is Wi-Fi?
> It is a way we use to get the devices to communicate wirelessly.

- Wi-Fi stands for what?
> Wireless Fidelity.

___
# MAN (Metropolitan Area Network)

The man network is bigger than the LAN and smaller than WAN.
You can say that MAN is btw cities and WAN is btw countries.

MAN is a group of connected LANs.
WAN is a group of connected MANs.

___
# What is a server

A server is a type of computers that shares information with other computers.
The ultimate function of a server is to receive, store, process, and share data.
The server provides services to others (request-response).
The server can be a software.

PC + Apache HTTP Server (software) = web server.

Server vs PC

|               Server               |                  PC                  |
| :--------------------------------: | :----------------------------------: |
|  High reliability & dependability  |   Less reliability & dependability   |
|          High performance          |           Low performance            |
| Can run for years without shutdown | Can't run for years without shutdown |
|       Less maintenance cost        |        High maintenance cost         |
|             High price             |              Low price               |

Reliability means the computer is always up.

Some types of servers:
- Web server
- Mail server
- Application server
- Database server
- File server
- Image server
- Many other servers

We communicate to a web server using http/https requests.

How to request from the terminal?
```powershell
 # from powershell
 Invoke-WebRequest https://google.com
 
 # using curl
 curl https://google.com
```

A server is a computer with high performance(CPU - RAM - CACHE).

We put servers in special spaces called Data Centers.

___
# How data is transferred (packets)

A packet is a part of a file.

How to send a file "file.txt" from pc1 to pc2?
pc1 splits the file into packets, sends them to pc2, then, pc2 collects the packets in order to get the final file.

___
# TCP (Transmission Control Protocol)

TCP defines how applications can create channels of communication across a network.
Is also manages how a message is assembled into smaller packets before they are then transmitted over the internet.
And reassembled in the right order at the destination address.

___
# IP Part 1 (IPv4)

The IP protocol is a collection of rules that regulate(ينظم) the format of data transferred over the internet or a local network.
The IP address identifies the network machines.
# IP Part 2 (IPv6)

We write it in hex.
`2001:0db8:0000:0000:ff00:0000:0042:8330` we can write this as
`2001:db8::ff00:0:42:8330` this is called the short version. (I did not get it a lot. Search for it if you want).
the zeros on left don't matter.
# IP Part 3 (IP Types)

1. Public
	- IP which can be seen on the internet is public.
	- The IP address assigned to the home's network by the ISP is known as a public IP address.
	- It can be static or dynamic.
2. Private
	- Private IP addresses ranges are defined under both IPv4 and IPv6 standards.
	- It can be static or dynamic.
3. Static
	- An IP address that doesn't change is known as a static IP address.
	- The majority of users do not require static IP addresses (it is expensive).
	- For example, you'll use one if you want to host your website on your server in your home.
4. Dynamic
	- A dynamic IP address changes from time to time. Because it is more cost-effective for ISPs to assign dynamic IP addresses to their clients.

___
# What is Gateway, Router, Modem, and Mesh Network?

You know the router.
The modem is the device on the building roof.
The Gateway is a router and modem in the same device.

In the router:
- 2.4 GHz has slower transmission but wide range in the house.
- 5 GHz is the inverse.

Your gateway is your point to the outside world.
The gateway has its own IP address.

I did not get the diff btw the router and the gateway.
What I know is that the gateway on my machine is the IP address that I sends to it every packet I don't connected to its destination.

Gateway:
- A computer that sits btw networks or applications.
- The gateway converts information, data or other communications from one protocol or format to another.
- A router may perform some of the functions of a gateway.
- An internet gateway can transfer communications btw an enterprise network and the internet.
- It can work like a translator btw two networks.

Gateway vs Router:
- A router is a device that is capable of sending and receiving data packets between computer networks.
- A gateway, on the other hand, joins dissimilar systems.
- Gateway is defined as a network entity that allows a network to interface(تتفاعل) with another network with diff protocols.

Mesh Network: it solves a problem, suppose that your house is really big, one router will not cover the whole house, so,
you can put mini Wifi devices that keeps the signal strong.

___
# IP Part 4 (DHCP)

DHCP stands for Dynamic Host Configuration Protocol.
Instead of giving the IP addresses to 1000 devices manually, you use DHCP to assign those IP addresses dynamically.
You can set rules for the gateway to follow.

___
# NAT and IP mapping
It is the NAT you know.

___
# ISP

Stands for Internet Service Provider.

___
# What is Port/Socket?

Port
- Hardware Port.
- Software Port.

You can run multiple services on the same server. For sure :)
Each service will have each own port.

IP address + Port = Socket address
`192.168.1.10:23`

> In networking, a socket is used to allow many processes within a single or different host to use TCP communication simultaneously.
> A port is a number assigned to uniquely identify a connection endpoint and to direct data to a specific service.
 
 The first sentence is not very clear, but, what I get is, the concept of sockets allow multiple processes to make TCP connections at the same time.
 I guess the second sentence is clear.

___
# What is Subnet Mask

> Subnetting is the practice of dividing a network into two or more smaller networks. It increases routing efficiency, enhances the security of the network.

Network classes
- A -> /8
- B -> /16
- C -> /24

This is the format of a subnet mask `255.255.0.0`

___
# What is MAC Address

The manufacturer assign this address to the device.

> MAC address is a unique number which is used to track a device in a network.
> MAC address provides a secure way to find senders or receivers in the network.
> It helps prevent unwanted network access.
> MAC address is also used in Wi-Fi networks at the airport for a specific device in order to identify it.

___
# What IP Address Reveals about us?

Smile :) Keep learning.
Nothing important.

---
# What is VPN?

Stands for Virtual Private Network.

> As you connect to a secure VPN server, your internet traffic goes through and encrypted tunnel that nobody can see into, including hackers, governments, and your internet service provider.

> It also changes your IP address completely.
> Placing your geolocation hundreds or maybe thousands of miles from where you are accessing the internet.

___
# Internet vs WWW

Internet = Interconnection + Network
The Internet is the network of networks.

> World Wide Web, or web is a collection of websites that are linked together through the internet.
> The web is the content you can view, read, listen to, stream, and download.
> Most websites have links that connect them to other websites.
> If you were to draw an image of all these links, it would look like a spiderweb made of websites around the globe(الكرة الأرضية). That's why it's called the World Wide Web.

___
# Surfing Internet (Browsers)

> Browser is a software application that lets people access the WWW.
> It is used to locate, fetch and display content on the internet, including web pages, images, videos, documents, and other files.
> In other words browser is the program that request a webpage and download it, interpret it and show it on the screen in the right format.

___
# Http vs Https Protocols

HTTP stands for Hyper Text Transfer Protocol.

We use it for transmitting hypermedia documents, such as HTML.

> It is a protocol used to access the data on the WWW.
> The HTTP protocol can be used to transfer the data in the form of plain text, hypertext, audio, video, and so on.

HTTP is more secure than HTTPS. It uses a protection layer SSL (Secured Socket Layer) or TLS (Transport Layer Security).

> TLS is higher security than SSL and more reliable and faster.

`https://www.ProgrammingAdvices.com` here `ProgrammingAdvices.com` is called domain name.

___
# What is Domain Name? From Where to Get One?

The domain name is unique.
Domain name (or simply the domain) of `ProgrammingAdvices` is `104.19.238.117`.

You can get a static IP from the ISP. Then buy a domain name, and connect them together.

> A domain name (often simply called a domain) is an easy-to-remember name that's associated with a physical IP address on the Internet.
> It's the unique name that appears after the `@` sign in email addresses, and after `www.` in web addresses.

___
# DNS

Stands for domain name server.

When you buy the domain name, you connect it to your IP address.

When it get the IP address of google.com it put it on your laptop, and refresh it from time to time.
In order to access google.com fast the next time you request it. So you have a DNS locally on your laptop :)

___
# Sub Domain Names

`https://SubDomain.DomainName.com`

> A subdomain name is a piece of additional information added to the beginning of a website's domain name.
> It allows websites to separate and organize content for a specific function, such as a blog or an online store, from the rest of your website. 

You only buy for the domain name. You can create subdomains as you want for free. You just configure that.

```
example.com

api.example.com
blog.example.com
```
___
# URL

Uniform Resource Locator.

> It is basically a reference to a web resource in the computer network.
> It provides the location of the resource and a mechanism to retrieve it.

`https://www.google.com/index.html`
- `https://` this is the protocol.
- `www` is a subdomain.
- `google.com` is the domain name.
- `com` is the top level domain.
- `www.google.com` is the resource name.
- `index.html` is the file path.

You can put `https://www.google.com:80/index.html` to specify the port.
You can put `https://www.google.com/index.html?var1=111&var2=222#00h`
- The `#00h` is called the fragment.
- The `?var1=111&var2=222` is called query string, it contains parameters(variables and values).

___
# FTP (File Transfer Protocol)

This is a specialized protocol for transfer files from/to another device.

> FTP is a way to download, upload, and transfer files from one location to another on the Internet and btw computer systems.

> Advantages of FTP:
> - Allows the transfer of multiple files and directories.
> - Ability to resume a transfer if the connection is lost.
> - Ability to put items into a queue to be uploaded or downloaded.
> - Allows you to schedule transfers.
> - No size limitation on single transfers (browsers only allow up to 2 GB)

___
# API

It stands for Application Programmable Interface.

You can make two programs, one in python and another with c# and make them communicate using the api concept.

Using apis, you can integrate the programs without caring about the language/OS used.

APIs is a web service you can call/use from anywhere.

APIs depends on HTTP protocol.

___
# Real Example about API

Click a button -> fire a function.
Call the API -> fire the same function.
In this way, you allow people to build on top of your software.

So, people can perform the features in your software using the UI, and also using the API.
___
# What is XML

It is not a programming language, it is a markup language.
We use it to store data in a good way. To present data in a good way.

Imagine you are reading some data that is written randomly in a file, and another data that is written in XML.
The XML one will be more readable.

We can consider it a database. Instead of storing the values of a struct in file separated with `#||#` for example, we can store them using XML.

The diff btw XML and other files, is that XML organize the data using tags.

There are libraries that help you deal with XML.

XML means eXtensible Markup Language. Which means, a language that describe its data/values, and it is extensible, which means you shape it as you want.
YOU write the tags. YOU decide the name of the tags. You have the freedom to do that.
YOU design the structure of your XML.

XML and HTML is text, so it is easy to send/receive it over Internet. Plus, the text files are light/small in size.
All platforms(Windows-Linux-Mac-IOS-Android) can read text.

> What is XML?
> - XML was designed to store and transport data.
> - XML was designed to be self-descriptive.
> - XML is widely used for data storage, exchange(send-receive), and configuration purposes.
> - It provides a platform-independent and standardized way to represent structured data, making it easier for different systems to exchange and interpret information.
> - XML stands for Extensible Markup Language. It is a markup language that is designed to store and transport data in a format that is both human-readable and machine-readable.

> XML simplifies things like:
> - XML simplifies data sharing.
> - XML simplifies data transport.
> - XML simplifies platform changes.
> - XML simplifies data availability.
> - XML simplifies XML + XSLT -> New format (html, pdf, word, ..etc)

> XML stores data in plain text format. This provides a software and hardware independent way of storing, transporting, and sharing data.

___
# What is JSON

It is similar to XML, but JSON is lighter, smaller, and faster. So, it is better to use it over XML.

Similar to XML, there are libraries help you deal and work with JSON.

You can store the application settings for example, the database connection string, color theme of the application, ..ETC.

XML and JSON examples
```xml
<People>
	<person>
		<name>Rohammed Abu-Hadhoud</name>
		<age>46</age>
		<city>Amman</city>
		<country>Jordan</country>
	</person>
	
	<person>
		<name> Ali Ahmad</name>
		<age>30</age>
		<city>Cairo</city>
		<country>Egypt</country>
	</person>
</People>
```

```JSON
{
	"People": {
		"person": [
			{
				"name": "Mohammed Abu-Hadhoud",
				"age": "46",
				"city": "Amman",
				"country": "Jordan"
			},
			{
				"name": "Ali Ahmad",
				"age": "30",
				"city": "Cairo",
				"country": "Egypt"
			}
		]
	}
}
```

> What is JSON?
> - JSON stands for JavaScript Object Notation.
> - JSON is a lightweight data-interchange format.
> - JSON is used to send data between computers.
> - JSON is a text format.
> - Used for storing and transporting data.
> - JSON is "self-describing" and easy to understand.
> - JSON is language independent.

> JSON (JavaScript Object Notation) is a lightweight data-interchange format. It is easy for humans to read and write. It is easy for machines to parse and generate.

> JSON Simplifies Things:
> - JSON simplifies data sharing.
> - JSON simplifies data transport.
> - JSON simplifies platform changes.
> - JSON simplifies data availability.

> JSON stores data in plain text format. This provides a software and hardware independent way of storing, transporting, and sharing data.

Questions:
Which is faster, storing data in files or in MSQLS?
	For simple data, config, static content, and logs use files.
	For complex application data use MSQLS.

___
# GUID

> A GUID (Globally Unique Identifier), also known as UUID (Universally Unique Identifier), is a 128-bit value that is used to uniquely identify objects or entities. It is designed to be <u>globally unique across all devices</u> and systems.

> A GUID consists of five groups of characters, typically represented as a string of hexadecimal digits separated by hyphens. For example, a GUID may look like this:
> `4efc3da2-63c5-4383-b3f1-ba6a8a0a1444`

> The uniqueness of a GUID is achieved by combining various components such as the MAC address of the network card, the current timestamp, and random bits. This combination ensures a very low probability of generating duplicate GUIDs.

example of timestamp (see the `Logintime`)
```
User: Yasin
LoginTime: 2026-03-10 18:42:15
```

> The chances of generating the same GUID twice are extremely small, even when multiple devices are generating GUIDs simultaneously. The sheer size of the 128-bit space allows for an astronomically(فلكي) large number of unique combinations, making collisions (two GUIDs being the same) highly unlikely.

This number is generated by an algorithm.
This number is unique. You can't ever find any copy to it, from any device from anywhere in any time.

In C#
```c#
using System;
Guid GuidNumber = Guid.NewGuid();
Console.WriteLine(GuidNumber);
```
In SQL
```sql
select newID();
```

For example, in SQL you can put
```sql
select * from dbo.Sailors
order by newID();
-- this will return the table ordered randomly in a diff way each time you execute the query
```

Programming = Information + Ideas + Logic(to merge the ideas).
Use/employee the information you know in programming.

___
# 3 Tier Architecture

presentation - interface 
```c
[1] Presentation Layer/Tier     <->     [2] Business Layer/Tier     <->     [3] Data Layer/Tier     <->     SQL Server (data)
Mobile-Website-Depstop apps             C# Classes and calculations         SQL Server & Stored Procedures
- User Interface                        - Middle Tier                       - Data access Tier                                  
- Client Tier                           - Business Logic                    - Persistence Tier
```
For example, if you want to add an IOS app, you only need to implement on the presentation layer.
Same thing if you want to add an API, you only need to work on the presentation layer. (I didn't get how :)

___
# What is Business Intelligence? and What is Cube?

Convert the data to information -> give a report (in the right time) to the people who make decisions

As a manager, the more information you get the more accurate your decisions will be.

Based on analyzing the data you can make dashboards.

You make decisions based on the information that is extracted from the data you have.

> If I can't measure it, I can't manage it.
> BI transforms raw Data into valuable Information.
> Information can be transformed into Knowledge through discovery.
> Business Intelligence (BI) is about getting the right information, to the right decision makers, at the right time.
> BI leads to :
> - Fact-based decision making not assumption-based decision making.
> - Single version of the truth.

> Common company problems:
> Data is distributed across the enterprise.
> Data everywhere, information nowhere.

> Questions!
> What happened? (past)
> What is happening? (present, dashboards)
> Why did it happen? (analysis)
> What will happen? (future, forecasting which means prediction based on the information we have)
> What do I want to happen? (panning)

> Benefits
> Give user the means to make better decisions.
> Leverage(تأثير) your investment in your legacy systems (e.g. ERP) or data warehouse, it is the best way to get value from existing applications.
> Challenge assumption with factual information.
> Eliminate report backlog and delays.
> Find root causes and take action.
> Identify waste resources and reduce cost.
> Improve operational efficiency.
> Creates organizational language.
> Negotiate better contracts(العقود) with suppliers and customers.
> Improve strategies with better marketing analysis.

> BI tools
> - Tableau
> - Power BI
> - Qlik Sense
> - Excel (Pivot Tables)
> - SAP BusinessObjects
> - Oracle BI
> - IBM Cognos Analytics
> - Many Others

___
# What is Security in Simple Terms

You keep adding security layers as you want.

Security is not only in the server or in the code, security is every where.

___
