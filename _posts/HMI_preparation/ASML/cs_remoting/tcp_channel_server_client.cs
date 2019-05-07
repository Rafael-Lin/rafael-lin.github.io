https://docs.microsoft.com/zh-tw/dotnet/api/system.runtime.remoting.channels.tcp.tcpchannel?redirectedfrom=MSDN&view=netframework-4.7.2
using System;
using System.Runtime.Remoting;
using System.Runtime.Remoting.Channels;
using System.Runtime.Remoting.Channels.Tcp;
using System.Security.Permissions;

public class Server
{
[SecurityPermission(SecurityAction.Demand)]
    public static void Main(string[] args)
    {
        TcpChannel serverChannel = new TcpChannel(9090);
        ChannelServices.RegisterChannel(serverChannel);
        Console.WriteLine("The name of the channel is {0}.", serverChannel.ChannelName);
        Console.WriteLine("The priority of the channel is {0}.", serverChannel.ChannelPriority);
        ChannelDataStore data = (ChannelDataStore) serverChannel.ChannelData;

        foreach (string uri in data.ChannelUris)
        {
            Console.WriteLine("The channel URI is {0}.", uri);
        }

        // Expose an object for remote calls.
        RemotingConfiguration.RegisterWellKnownServiceType(
            typeof(RemoteObject), "RemoteObject.rem", 
            WellKnownObjectMode.Singleton);

        // Parse the channel's URI.
        string[] urls = serverChannel.GetUrlsForUri("RemoteObject.rem");
        if (urls.Length > 0)
        {
            string objectUrl = urls[0];
            string objectUri;
            string channelUri = serverChannel.Parse(objectUrl, out objectUri);
            Console.WriteLine("The object URL is {0}.", objectUrl);
            Console.WriteLine("The object URI is {0}.", objectUri);
            Console.WriteLine("The channel URI is {0}.", channelUri);
        }
        
        // Wait for the user prompt.
        Console.WriteLine("Press ENTER to exit the server.");
        Console.ReadLine();
    }
}

-- 
using System;
using System.Runtime.Remoting;
using System.Runtime.Remoting.Channels;
using System.Runtime.Remoting.Channels.Tcp;
using System.Security.Permissions;

public class Client
{
[SecurityPermission(SecurityAction.Demand)]
    public static void Main(string[] args)
    {
        TcpChannel clientChannel = new TcpChannel();
        ChannelServices.RegisterChannel(clientChannel, false);

        // Register as client for remote object.
        WellKnownClientTypeEntry remoteType = new WellKnownClientTypeEntry(
            typeof(RemoteObject),"tcp://localhost:9090/RemoteObject.rem");
        RemotingConfiguration.RegisterWellKnownClientType(remoteType);

        // Create a message sink.
        string objectUri;
        System.Runtime.Remoting.Messaging.IMessageSink messageSink = 
            clientChannel.CreateMessageSink(
                "tcp://localhost:9090/RemoteObject.rem", null, out objectUri);
        Console.WriteLine("The URI of the message sink is {0}.", objectUri);
        if (messageSink != null)
        {
            Console.WriteLine("The type of the message sink is {0}.", messageSink.GetType().ToString());
        }

        // Create an instance of the remote object.
        RemoteObject service = new RemoteObject(); 

        // Invoke a method on the remote object.
        Console.WriteLine("The client is invoking the remote object.");
        Console.WriteLine("The remote object has been called {0} times.", service.GetCount());
    }
}

-- 
using System;
using System.Runtime.Remoting;

// Remote object.
public class RemoteObject : MarshalByRefObject
{
    private int callCount = 0;

    public int GetCount()
    {
        callCount++;
        return(callCount);
    }
}
