Raypack Suite 
======
           
Raypack Suite is a video, audio and encryption realtime plattform. 
It supports the Raypack Image Format, Raypack Container Format, optimized H.264 Encoding, HEVC Encoding, VP9 Encoding
Several Image Filters like Adaptive Sharping and many more feature.

The main plattform is based on low power devices based on ARM 64 CPU´s as well Nvidia embedded GPU Modules.
The fork uses sources from Bento, Libav, OpenRealtime Cuda, GPAC, NicEncryption, Open SSL.
The main OS is Unix and optmized for Ubuntu LTS. 


Features
--------

A number of formats and features based on the ISO-MP4 format and related technologies are also supported, including:

 * MPEG DASH with fragmented MP4 files, as defined in ISO/IEC 23009-1
 * MPEG Common Encryption (CENC) as specified in ISO/IEC 23001-7
 * PIFF (Protected Interoperable File Format): encrypted, fragmented MP4 format specified by Microsoft and used for encrypted HTTP Smooth Streaming.
 * Reading and writing 3GPP and iTunes-compatible metadata.
 * ISMA Encrytion and Decryption as defined in the ISMA E&A specification
 * OMA 2.0 and 2.1 DCF/PDCF Encryption and Decryption as defined in the OMA specifications.
 * ISO-MP4 files profiled as part of the 3GPP family of standards.
 * The UltraViolet (DECE) CFF (Common File Format).
 * Parsing and multiplexing of H.264 (AVC) video and AAC audio elementary streams
 * Support for multiple DRM systems that are compatible with MP4-formatted content (usually leveraging CENC Common Encryption), such as Marlin, PlayReady and Widevine.
 * Support for a wide range of codecs, including H.264 (AVC), H.265 (HEVC), AAC, AC3 and eAC3 (Dolby Digital), DTS, ALAC, and many more.


License
-------

The library is Open Source, GPL & AGPL based (GNU Affero General Public License).

Wiki:
https://de.wikipedia.org/wiki/GNU_Affero_General_Public_License

Patents
-------
Please make sure that you have all patent rights cleared before you start using these tools. For H.264 and HEVC as well for MpegTS, make sure to check
the rights with MpegLA, http://www.mpegla.com/SitePages/Home.aspx. For Dolby with Dolby Laboratories, http://www.dolby.com/us/en/professional/licensing.html.
For AAC Licesnsing visit http://www.vialicensing.com/licensing/aac-fees.aspx. 

We included in this release the following command line tools.
---------------------

These command-line applications/tools that are built using the SDK API. 

These include:

|app name       | description
|---------------|------------------
|mp4info	    | displays high level info about an MP4 file, including all tracks and codec details                                                              
|mp4dump	    | displays the entire atom/box structure of an MP4 file                                                                                           
|mp4edit	    | add/insert/remove/replace atom/box items of an MP4 file                                                                                         
|mp4extract	    | extracts an atom/box from an MP4 file                                                                                                           
|mp4encrypt	    | encrypts an MP4 file (multiple encryption schemes are supported)                                                                                
|mp4decrypt	    | decrypts an MP4 file (multiple encryption schemes are supported)                                                                                
|mp4dcfpackager | encrypts a media file into an OMA DCF file                                                                                                      
|mp4compact	    | converts ‘stsz’ tables into ‘stz2′ tables to create more compact MP4 files                                                                      
|mp4fragment    | creates a fragmented MP4 file from a non-fragmented one or re-fragments an already-fragmented file                                              
|mp4split	    | splits a fragmented MP4 file into discrete files                                                                                                
|mp4tag	        | show/edit MP4 metadata (iTunes-style and others)                                                                                                
|mp4mux	        | multiplexes one or more elementary streams (H264, AAC) into an MP4 file                                                                         
|mp42aac	    | extract a raw AAC elementary stream from an MP4 file                                                                                            
|mp42avc	    | extract a raw AVC/H.264 elementary stream from an MP4 file                                                                                      
|mp42hls	    | converts an MP4 file to an HLS (HTTP Live Streaming) presentation, including the generation of the segments and .m3u8 playlist.
|mp42ts	        | converts an MP4 file to an MPEG2-TS file.
|mp4-dash	    | creates an MPEG DASH output from one or more MP4 files, including encryption.                                                                   
|mp4-dash-clone	| creates a local clone of a remote or local MPEG DASH presentation, optionally encrypting the segments as they are cloned.

Building
--------

The code can be built either by MakefileARM. Please make sure that you have the latest ARM Toolchain installed for 64 Bit OS, GCC 4.xx or later and
also the latest YASM. These tools are only for ARM based CPU Architecture, it may work with X86 / 64 Bit as well.

Please also make sure that you have Nvidia CUDA SDK, LibAV Libs, OpenSSL installed properly.


If you need custom development, patent clearing help or other support, please contact us: http://connectlounge.de/contact
